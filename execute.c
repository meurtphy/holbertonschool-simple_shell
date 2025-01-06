#include "shell.h"

/**
 * execute_command - Exécute une commande.
 * @args: Les arguments de la commande (tableau de chaînes).
 */
void execute_command(char **args)
{
pid_t child_pid;
int status;

if (!args || !args[0])
return;

child_pid = fork();
if (child_pid == -1)
{
perror("Erreur avec fork");
return;
}

if (child_pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
fprintf(stderr, "./shell: %s: No such file or directory\n", args[0]);
exit(EXIT_FAILURE);
}
}
else
wait(&status);
}


