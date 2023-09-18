#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define RL_BUFSIZE 1024
#define DELIM " \t\n"
#define MAX_COMMAND_LENGTH 1024

extern char env;

char *_strdup(char *str);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);

char *read_line(void);
char *read_cmd();
char **get_token(char *line);
void execmd(char **arg);

#endif