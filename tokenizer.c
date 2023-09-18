#include "main.h"

char **get_token(char *line)
{
	char *tkn = NULL, *tmp = NULL;
	char **arg = NULL;
	int count = 0, i = 0;

	if (line == NULL)
		return (NULL);

	tmp = strdup(line);

	tkn = strtok(tmp, " ");
	if (!tkn)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
	}

	while (tkn)
	{
		count++;
		tkn = strtok(NULL, " ");
	}
	free(tmp), tmp = NULL;

	arg = malloc(sizeof(char *) * (count + 1));
	if(!arg)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tkn = strtok(line, " ");

	while(tkn)
	{
		arg[0] = tkn;
		tkn = strtok(NULL, " ");
		i++;
	}
	free(line), line = NULL;
	arg[count] = NULL;

	return (arg);
}