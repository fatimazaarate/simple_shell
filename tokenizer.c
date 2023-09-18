#include "main.h"

char **get_token(char *line)
{
	char *tkn = NULL, *line_copy = NULL;
	char **arg = NULL;
	int count = 0, i = 0;


	if (line == NULL)
		return (NULL);

	line_copy = strdup(line);

	tkn = strtok(line_copy, DL);
	if (!tkn)
	{
		free(line), line = NULL;
		return (NULL);
	}

	while (tkn)
	{
		count++;
		tkn = strtok(NULL, DL);
	}
	free(line_copy), line_copy = NULL;

	arg = malloc(sizeof(char *) * (count + 1));
	if(!arg)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tkn = strtok(line, DL);

	while(tkn)
	{
		arg[i] = strdup(tkn);
		tkn = strtok(NULL, DL);
		i++;
	}
	free(line), line = NULL;
	arg[count] = NULL;

	i = 0;

	while (arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}

	return (arg);


}
