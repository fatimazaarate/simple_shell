#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 *
 * Return: 0
 *
 */
char *_strdup(char *str)
{
	char *dup;
	int n, i;

	if (str == NULL)
		return (NULL);

	n = strlen(str);
	dup = (char *) malloc((n + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}


char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			return environ[i] + strlen(name) + 1;
		}
		i++;
	}
	return NULL;
}


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



int main(int ac,char **av)
{
	char *path;

	path = _getpath(av[1]);
	if (path)
		{
		printf("%s\n", path);
		free(path);
		}
	else
		printf("not ex");
	free(path);

	return 0;
} 