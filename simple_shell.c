#include "main.h"

int main(int ac, char **argv)
{
	char *cmd = NULL;
	int status = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)  /* reach EOF */
		{
			if (isatty(STDIN_FILENO))
				printf ("\n");
			return(status);
		}
	/*printf ("%s", cmd);*/
	tokenize_command(cmd, argv);
	execute_command(argv);
	}
return (0);
}
