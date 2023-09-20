#include "main.h"


int cmd_blt_in(char *cmd)
{
	char *blt = "exit";

	if (_strcmp(cmd, blt) == 0)
		return (1);

	return (0);
}

void bltin_handle(char **cmd, int st)
{

	if (_strcmp(cmd[0], "exit") == 0)
	{
		free(cmd);
		exit(st);
	}
}
