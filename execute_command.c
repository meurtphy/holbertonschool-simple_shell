#include "shell.h"

void execute_command(char *command)
{
char *argv[2];

argv[0] = command;
argv[1] = NULL;

if (execve(argv[0], argv, environ) == -1)
perror("./shell");
exit(EXIT_FAILURE);
}
