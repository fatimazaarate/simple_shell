#include "main.h"

int main(int ac, char **argv)
{
	char *prmpt = "Shell>$ ";
	char *cmd, *cmd_copy = NULL;
	size_t n = 0;
	ssize_t chars_number;
	char *del = " \n";
	int num_tkns = 0;
	char *tkn;
	int i;

	(void) ac;

	/* create a loop */
	
	while(1)
	{
		printf("%s", prmpt);
		chars_number = getline(&cmd, &n, stdin);
		/* check if getline fails */
		if (chars_number == -1)
		{
			printf("\n");
			return (-1);
		}
	/* allocate space for a copy of cmd*/
	cmd_copy = malloc(sizeof(char) * chars_number);
	if (cmd_copy == NULL)
		return (-1);

	/* copy cmd to cmd_copy */
	strcpy(cmd_copy, cmd);

	/* parsing*/
	tkn = strtok(cmd, del);
	
	while (tkn)
	{
		num_tkns++;
		tkn = strtok(NULL, del);
	}
	num_tkns++;
	
	/*alocate for argv*/
	argv = malloc(sizeof(char *) * num_tkns);

	/*alocate space to hold the arr of str*/
	tkn = strtok(cmd_copy, del);

	for (i = 0; tkn != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(tkn));
		strcpy(argv[i], tkn);
	
	/*for (count = 0; count < num_tkns - 1; count ++)
	{
		printf ("%s\n", argv[count]);		
	}*/
		tkn = strtok(NULL, del);
	}
	argv[i] = NULL;

	/*for (count = 0; count < num_tkns - 1; count++)
	{
		printf("%s\n", argv[count]);
		free(argv[i]);
	}*/
	execmd(argv);
	}

		free(argv), argv = NULL;
		free(cmd_copy), cmd_copy = NULL;
		free(cmd); cmd = NULL;


		return (0);
}
