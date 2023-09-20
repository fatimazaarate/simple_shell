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

#define DELIM " \t\n"


extern char **environ;

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);

char *read_line(void);
char *read_cmd();
char **get_token(char *line);
int execmd(char **cmd, char **argv);
void free_cmd(char **cmd);

int cmd_blt_in(char *cmd);
void bltin_handle(char **cmd, int st);


#endif
