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



char *_getpath(char *command)
{
	char *path = getenv("PATH");
	char *token;
	int i;
	 struct stat st;
	char *full_path = malloc(sizeof(char) * (strlen(command) + 1 + 256));
/* Assuming maximum path length of 256*/	
		

	if (path == NULL || full_path == NULL) {
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
		printf("%s\n", path);
	else
		printf("not ex\n");

	return 0;
} 
