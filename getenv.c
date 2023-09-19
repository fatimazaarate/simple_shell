#include "main.h"


char *_getenv(const char *name)
{
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