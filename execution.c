#include "main.h"


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
		p_error(argv[0], cmd[0], ind);
		free_cmd(cmd);
		free(full_command), full_command = NULL;
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
