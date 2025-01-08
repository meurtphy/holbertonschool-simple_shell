#include "shell.h"

extern char **environ;

void execute_command(char *command)
{
char *argv[2];

argv[0] = command;
argv[1] = NULL;

if (execve(argv[0], argv, environ) == -1)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", command);
_exit(EXIT_FAILURE);
}
}

