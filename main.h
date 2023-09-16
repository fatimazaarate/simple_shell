#ifndef MAIN_H
#define MAIN_M

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void tokenize_command(char *command, char **args);
void execute_command(char **args);
char *read_cmd();


#endif
