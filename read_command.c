#include "main.h"

/**
* read_line - function that reads commands
*
* Return: Nothing
*/

char *read_line(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char *shell = "Shell>$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, shell, strlen(shell));

	chars_read = getline(&cmd, &n, stdin);
	if (chars_read == -1)
	{
		free(cmd), cmd = NULL;
		return (NULL);
	}
	return (cmd);
}
