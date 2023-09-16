#include "main.h"

void tokenize_command(char *command, char **args)
{
	char *token = strtok(command, " ");
	int i = 0;
	while (token != NULL) {
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}

void execute_command(char **args) {
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Fork failed.\n");
		exit(1);
	}
	else if (pid == 0) {
		execvp(args[0], args);
		printf("Command not found.\n");
		exit(0);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		printf("Child process exited with status: %d\n", status);
	}
}

void run_shell()
	{
	char command[MAX_COMMAND_LENGTH];
	char *args[64];

	while(1)
	{
		printf("Shell>$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		command[strcspn(command, "\n")] = '\0';

		tokenize_command(command, args);

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	execute_command(args);
	}
}
