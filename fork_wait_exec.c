#include "shell.h"
void fork_wait_exec(char *command, char **env, char *prog_name)
{
char **argv;
char *resolved_path;
pid_t pid; /* Déclarez ici, avant tout autre code */

argv = split_command(command);
if (!argv || !argv[0])
{
free(argv);
return;
}

resolved_path = resolve_path(argv[0]);
if (!resolved_path)
{
fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
free(argv);
return;
}

pid = fork(); /* Déplacez l'appel après les déclarations */
if (pid == -1)
{
perror("fork");
free(resolved_path);
free(argv);
return;
}

if (pid == 0)
{
execve(resolved_path, argv, env);
perror("execve");
free(resolved_path);
free(argv);
_exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
free(resolved_path);
free(argv);
}
}
