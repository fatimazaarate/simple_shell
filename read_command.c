#include "main.h"

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char *shell = "Shell>$ ";

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, shell, strlen(shell));

	chars_read = getline(&cmd, &n, stdin);
	if (chars_read == -1)
	{
		free(cmd);
		return (NULL);
	}

	return (cmd);
}