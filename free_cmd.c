#include "main.h"


void free_cmd(char **cmd)
{
	int i = 0;

	if (!cmd)
		return;

	while (cmd[i])
	{
		free(cmd[i]), cmd[i] = NULL;
		i++;
	}

	free(cmd), cmd = NULL;
}
