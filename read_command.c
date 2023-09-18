#include "main.h"

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t r;
	char *shell = "Shell>$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, shell, strlen(shell));

	r = getline(&cmd, &n, stdin);
	if (r == -1)
	{
		free(cmd);
		return (NULL);
	}

	return (cmd);
}
