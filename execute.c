#include "shell.h"

extern char **environ;
void execute_command(char *command)
{
char *argv[] = {command, NULL};
if (execve(command, argv, environ) == -1)
{
perror(command);
exit(EXIT_FAILURE);
}
}
