#include "shell.h"

char **split_command(char *command)
{
int bufsize = 64, i = 0;
char **argv = malloc(bufsize * sizeof(char *));
char *arg;

if (!argv)
exit(EXIT_FAILURE);

arg = strtok(command, " ");
while (arg)
{
argv[i++] = arg;
if (i >= bufsize)
{
bufsize += 64;
argv = realloc(argv, bufsize * sizeof(char *));
if (!argv)
exit(EXIT_FAILURE);
}
arg = strtok(NULL, " ");
}
argv[i] = NULL;
return (argv);
}

void fork_wait_exec(char *command, char **env)
{
char **argv = split_command(command);
char *resolved_path = NULL;

if (access(argv[0], X_OK) == 0)
resolved_path = strdup(argv[0]);
else
resolved_path = resolve_path(argv[0]);

if (!resolved_path)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
free(argv);
return;
}

pid_t pid = fork();

if (pid == -1)
{
free(resolved_path);
free(argv);
return;
}

if (pid == 0)
{
argv[0] = resolved_path;
execve(argv[0], argv, env);
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
