#include "main.h"

int execmd(char **cmd, char **argv, int ind);
/**
* free_cmd - a function to free the memory
* @cmd: the memory to be freed
*/

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

void _printerror(char *name, char *cmd, int ind)
{
	char *idx;
	char msg[] = ": not found\n";

	idx = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx);
}



/**
* execmd - a function that executes commands
* @cmd: command to be executed
* @argv: program's arguments
*
* Return: exit status of the executed command
*/

int execmd(char **cmd, char **argv, int ind)
{
	char *full_command;
	pid_t ch;
	int status;

	full_command = _getpath(cmd[0]);
	if (!full_command)
	{
		_printerror(argv[0], cmd[0], ind);
		free_cmd(cmd);
		return (127);
	}

	ch = fork();
	if (ch == 0)
	{
		if (execve(full_command, cmd, environ) == -1)
		{
			free(full_command), full_command = NULL;
			free_cmd(cmd);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		free_cmd(cmd);
		free(full_command), full_command = NULL;
	}
	return (WEXITSTATUS(status));
}
