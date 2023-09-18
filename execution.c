#include "main.h"

void execmd(char **arg)
{
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        /* Child process */
        execvp(arg[0], arg);
        printf("Command not found.\n");
        exit(0);
    } else {
        /*Parent process */
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status: %d\n", status);
    }
}