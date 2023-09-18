#include "main.h"

int execmd(char **cmd, char **argv)
{
	pid_t kid;
	int stat;

	kid = fork();
	if (kid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
		perror(argv[0]);
		faos(cmd);
		exit(0);
		}
	}
	else
	{
		waitpid(kid, &stat, 0);
		faos(cmd);
	}
	return (WEXITSTATUS(stat));
}