#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *_getenv(const char *name) {
	extern char **environ;
	int i = 0;
	while (environ[i] != NULL) {
		if (strncmp(name, environ[i], strlen(name)) == 0) {
			return environ[i] + strlen(name) + 1;
		}
		i++;
	}
	return NULL;
}

char *_getpath(char *command) {
	if (command[0] == '/') {
		return command;
	} else {
		char *path = _getenv("PATH");
		if (path == NULL) {
			return NULL;
		}
		char *token = strtok(path, ":");
		while (token != NULL) {
			char *full_path = malloc(strlen(token) + strlen(command) + 2);
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command);
			if (access(full_path, F_OK) == 0) {
				return full_path;
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
		return NULL;
	}
}

int main(int ac,char **av)
{
	char *path;

	path = _getpath(av[1]);
	if (path)
		printf("%s\n", path);
	else
		printf("not ex");

	return 0;
} 