#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *local_argv[2]; /* Déclaration déplacée ici, au début du bloc */

    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            return (0);
        }

        local_argv[0] = line;
        local_argv[1] = NULL;

        if (execve(line, local_argv, environ) == -1)
        {
            perror("execve");
        }
    }

    free(line);
    return (0);
}
