#include "shell.h"

void execute_command(char *resolved_path, char **argv, char **env)
{
if (execve(resolved_path, argv, env) == -1)
perror("execve");

_exit(EXIT_FAILURE);
}
