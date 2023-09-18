#include "main.h"

void free_cmd(char **cmd)
{
	int j;

	if (cmd == NULL)
		return;

	for (j = 0; cmd[j]; j++)
	{
		free(cmd[j]);
		cmd[j] = NULL;
	}

	free(cmd), cmd = NULL;
}


int execmd(char **cmd, char **argv)
{
	pid_t ch;
	int status;
	
	ch = fork();
	if (ch == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free_cmd(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		free_cmd(cmd);
	}
	return(WEXITSTATUS(status));
}
