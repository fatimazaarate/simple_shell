#include "main.h"

int main( int ac, char **argv)
{
	char *cmd;
	char **args = NULL;
	int status = 0, i = 0;

	(void)ac;
	(void)argv;

	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		/*printf("%s", cmd);*/
		

		args = get_token(cmd);
		if (args == NULL)
			continue;

		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}
		free(args);
	}
}	
