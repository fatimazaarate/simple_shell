#include "main.h"

void execmd(char **arg)
{
	char *cmd = NULL;

	if (arg)
	{
		cmd = arg[0];

	if (execve(cmd, arg, NULL) == -1)
		perror("error");
	}
}