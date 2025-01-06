#include "shell.h"

/**
 * execute_command - Exécute une commande simple sans arguments.
 * @command: La commande à exécuter.
 */
void execute_command(char *command)
{
pid_t child_pid;
int status;

if (!command || strlen(command) == 0) /* Si la commande est vide */
return;

child_pid = fork();
if (child_pid == -1)
{
perror("Erreur avec fork");
return;
}

if (child_pid == 0)
{
char *argv[] = {command, NULL};
if (execve(command, argv, environ) == -1)
{
fprintf(stderr, "./shell: %s: No such file or directory\n", command);
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}


