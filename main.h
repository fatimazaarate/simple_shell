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
#include <stdbool.h>

#define DELIM " \t\n"

extern char **environ;

char *_strdup(char *str);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_itoa(int n);
void reverse_string(char *str, int len);


char *read_line(void);
char **get_token(char *line);
void _printerror(char *name, char *cmd, int ind);
int execmd(char **cmd, char **argv, int ind);
void free_cmd(char **cmd);
char *_getenv(const char *var);
char *_getpath(char *command);



#endif
