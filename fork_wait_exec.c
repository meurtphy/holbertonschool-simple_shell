#include "shell.h"

void fork_wait_exec(char *command)
{
char *resolved_path = NULL;

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
printf("Executing: %s\n", resolved_path);
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
free(resolved_path);
return;
}

if (pid == 0)
{
execute_command(resolved_path);
free(resolved_path);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
free(resolved_path);
}
}
