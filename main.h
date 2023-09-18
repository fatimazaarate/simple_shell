#ifndef MAIN_H
#define MAIN_M

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define DL " \n"


char *read_cmd();
char **get_token(char *line);
void execmd(char **arg);

#endif
