#include "main.h"

/**
* main - Entry point
* @ac: number of arguments
* @argv: array of arguments
*
* Return: exit status
*/

int main(int ac, char **argv)
{
	char *ln = NULL;
	char **cmd = NULL;
	int stat = 0, idx = 0;
	(void) ac;

	while (1)
	{
		ln = read_line();
		if (ln == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(ln), ln = NULL;
			return (stat);
		}
		idx++;
		cmd = get_token(ln);
		if (!cmd)
			continue;


		stat = execmd(cmd, argv, idx);
	
	}
}

