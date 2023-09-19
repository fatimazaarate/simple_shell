#include <unistd.h>
#include <stdio.h>
#include <string.h>

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




int main()
{
    char *value;

     value = _getenv("PWD");
    printf("Value of PATH: %s\n", value);

    value = _getenv("PATH");
    printf("Value of PATH: %s\n", value);

    value = _getenv("HOME");
    printf("Value of HOME: %s\n", value);

    value = _getenv("SHELL");
    printf("Value of SHELL: %s\n", value);
    return 0;
}