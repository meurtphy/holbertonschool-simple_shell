#include "shell.h"

extern char **environ;

void execute_command(char *command)
{
char *resolved_path = NULL;
char *argv[2];

if (access(command, X_OK) == 0)
{
resolved_path = strdup(command);
}
else
{
resolved_path = resolve_path(command);
}

if (!resolved_path)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", command);
return;
}

argv[0] = resolved_path;
argv[1] = NULL;

if (execve(argv[0], argv, environ) == -1)
{
perror("execve");
}

free(resolved_path);
_exit(EXIT_FAILURE);
}
