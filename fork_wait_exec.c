#include "shell.h"

/**
 * fork_wait_exec - Crée un processus enfant, exécute et attend.
 * @command: Commande à exécuter.
 */
void fork_wait_exec(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("Erreur de fork");
return;
}

if (pid == 0)
{

execute_command(command);
exit(0);
}
else
{

int status;
do
{
waitpid(pid, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}

