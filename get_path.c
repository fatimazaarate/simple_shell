#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


char *_strdup(char *str)
{
	char *strdp;
	unsigned int i, j;

	if (str == 0)
	return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{}
	strdp = (char *) malloc(sizeof(char) * (i + 1));

	if (strdp == 0)
	return (NULL);

	for (j = 0; j < i; j++)
	strdp[j] = str[j];

	strdp[j] = '\0';

	return (strdp);
}


char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (p);
}
int _strlen(const char *s)
{
	int len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
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


char *_getpath(char *cmd)
{
	char *path;
	char *token;
	 struct stat st;
	char *full_path;


	path = _getenv("PATH");

	token = strtok(path, ":");
	while (token != NULL)
    	{
		full_path = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (full_path)
		{
			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, cmd);
			if (stat(full_path, &st) == 0)
			{
				free(path);
				return (full_path);
			}
		free(full_path), full_path = NULL;
		token = strtok(NULL, ":");
		}
	}

	free(path);
	return NULL;

}

int main(int ac,char **av)
{
	char *path;

	path = _getpath(av[1]);
	if (path)
		printf("%s\n", path);
	else
		printf("not ex\n");

	return 0;
} 
