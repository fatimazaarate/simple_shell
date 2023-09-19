#include "main.h"

char *_getpath(char *command)
{
	char *path = getenv("PATH");
	char *token;
	int i;
	 struct stat st;
	char *full_path = malloc(sizeof(char) * (strlen(command) + 1 + 256));
		

	if (path == NULL || full_path == NULL)
	{
		return NULL;
	}

	for (i = 0; command[i]; i++) /*to handle absolute path /bin/ls */
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			return (_strdup(command));
		return (NULL);
		}
	}
	if (!path)   /* to handle unset PATH */
		return (NULL);

	token = strtok(path, ":");
	while (token != NULL)
    {
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, F_OK) == 0)
        {
			return full_path;
		}
		token = strtok(NULL, ":");
	}

	free(full_path);
	return NULL;
}