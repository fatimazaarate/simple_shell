#include "main.h"

/*t main(int ac, char **argv)
{
	char *prmpt = "Shell>$ ";
	char *cmd = NULL, *cmd_copy = NULL;
	size_t n = 0;
	ssize_t chars_number;
	char *del = " \n";
	int num_tkns = 0;
	char *tkn;
	int i, count = 0;
	char ** args = NULL;

	(void) ac;

	* create a loop */
	
	/*while(1)
	{
		printf("%s", prmpt);
		chars_number = getline(&cmd, &n, stdin);
		* check if getline fails */
		/*if (chars_number == -1)
		{
			printf("\n");
			free(cmd);
			return (-1);
		}
	* allocate space for a copy of cmd*/
	/*cmd_copy = malloc(sizeof(char) * chars_number);
	if (cmd_copy == NULL)
	{
		free(cmd);
		 return (-1);
	}

	* copy cmd to cmd_copy */
	/*strcpy(cmd_copy, cmd);

	* parsing*/
	/*tkn = strtok(cmd_copy, del);
	
	if (!tkn)
	{
		free(cmd_copy), cmd_copy = NULL;
	}
	
	while (tkn)
	{
		num_tkns++;
		tkn = strtok(NULL, del);
	}
	num_tkns++;

	free(cmd_copy), cmd_copy = NULL;
	
	*alocate for argv*/
	/*args = malloc(sizeof(char *) * num_tkns);
	if (!args)
	{
		free(cmd), cmd = NULL;
		return (-1);
	}

	*alocate space to hold the arr of str*/
/*kn = strtok(cmd, del);

	for (i = 0; tkn != NULL; i++)
	{
		args[i] = strdup(tkn);
	
		tkn = strtok(NULL, del);
	}

	free(cmd), cmd = NULL;
	args[i] = NULL;

	for (count = 0; count < num_tkns - 1; count++)
	{
		printf("%s\n", args[count]);
		free(args[count]);
	}
	*execmd(argv);*/


/*ree(argv), argv = NULL;
	}

		return (0);
}*/
