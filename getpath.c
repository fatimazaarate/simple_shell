#include "main.h"


char *_getpath(char *command)
{
	char *path, *fcmd, *cpath;
	struct stat st;
	int i = 0;

	while (command[i])
	{
		if (command [i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	cpath = strtok(path, ":");	
	while (cpath)
	{
		fcmd = malloc(_strlen(cpath) + _strlen(command) + 2);
		if (fcmd)
		{
			_strcpy(fcmd, cpath);
			_strcat(fcmd, "/");
			_strcat(fcmd, command);
			if (stat(fcmd, &st) == 0)
			{
				free(path);
				return (fcmd);
			}
			free(fcmd), fcmd = NULL;
			cpath = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
