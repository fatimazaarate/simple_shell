#include "main.h"


char *_getenv(char *name)
{
	char *tmp, *ky, *val, *env;
	int i = 0;

	while (environ[i])
	{
		tmp = _strdup(environ[i]);
		ky = strtok(tmp,"=");

		if (_strcmp(ky, name) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
		i++;
	}
	return (NULL);
}
