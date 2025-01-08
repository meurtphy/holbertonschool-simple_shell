#include "shell.h"

void fork_wait_exec(char *command, char **env, char *prog_name)
{
char **argv = split_command(command);
char *resolved_path = NULL;
pid_t pid;

if (access(argv[0], X_OK) == 0)
resolved_path = strdup(argv[0]);
else
resolved_path = resolve_path(argv[0]);

if (!resolved_path)
{
fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
free(argv);
return;
}

pid = fork();

if (pid == -1)
{
perror("fork");
free(resolved_path);
free(argv);
return;
}

if (pid == 0)
{
argv[0] = resolved_path;
execve(argv[0], argv, env);
perror("execve");
free(resolved_path);
free(argv);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
free(resolved_path);
free(argv);
}
}

