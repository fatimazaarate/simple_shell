char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	struct  stat st;

	path_env = _getenv("PATH");

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen (command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) ==0)
			{
				free(path_env);
				return(full_cmd);
			}
			free(full_cmd), full_cmd =NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

#include "main.h"


char *_getenv(const char *var)
{
	char *tmp, *key, *value, *env;
    int i;

    for (i = 0; environ[i]; i++)
    {
        tmp = _strdup(environ[i]);
        key = strtok(tmp, "=");
        if (_strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);
            return (env);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
