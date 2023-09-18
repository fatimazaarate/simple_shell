#include "main.h"

char **get_token(char *line)
{
	char *tkn = NULL, *line_copy = NULL, *del = " ";
	char **arg = NULL;
	int count = 0, i = 0;


	if (line == NULL)
		return (NULL);

	line_copy = strdup(line);

	tkn = strtok(line_copy, del);
	if (!tkn)
	{
		/*free(line), line = NULL;*/
		free(line);
		return (NULL);
	}

	while (tkn)
	{
		count++;
		tkn = strtok(NULL, del);
	}
	free(line_copy);

	arg = malloc(sizeof(char *) * (count + 1));
	if(!arg)
	{
		/*free(line), line = NULL;*/
		return (NULL);
	}

	tkn = strtok(line, del);

	while(tkn)
	{
		arg[i] = tkn;
		tkn = strtok(NULL, del);
		i++;
	}
	/*free(line), line = NULL;*/
	arg[count] = NULL;

	/*i = 0;

	while (arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}*/

	return (arg);
}
