#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

char *_getenv(char *name)
{
	char *tmp, *ky, *val, *env;
	int i = 0;

	extern char **environ;

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
