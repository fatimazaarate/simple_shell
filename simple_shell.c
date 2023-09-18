#include "main.h"

int main(int ac, char **argv)
{
	char *ln = NULL;
	char **cmd = NULL;
	int stat = 0;
	(void) ac;

	while (1)
	{
		ln = read_line();
		if (ln == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDERR_FILENO, "\n", 1);
			return (stat);
		}
		cmd = get_token(ln);
		if (!cmd)
			continue;

		stat = execmd(cmd, argv);

	}
}