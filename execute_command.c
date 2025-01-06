#include "shell.h"

/**
 * execute_command - Exécute une commande simple sans arguments.
 * @command: La commande à exécuter.
 */
void execute_command(char *command)
{
pid_t pid;
int status;
char *argv[2];

argv[0] = command;
argv[1] = NULL;

pid = fork();
if (pid == 0)
{
if (execve(command, argv, environ) == -1)
{
print_error("./hsh", command);
exit(EXIT_FAILURE);
}
}
else if (pid > 0)
{
wait(&status);
}
else
{
perror("fork");
}
}

