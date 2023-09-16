#include "main.h"

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t r;

	if (isatty(STDIN_FILENO))
		printf("Shell>$ ");

	r = getline(&cmd, &n, stdin);
	if (r == -1)
	{
		free(cmd);
		return (NULL);
	}

	return (cmd);
}
