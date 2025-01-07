#include "shell.h"

/**
 * execute_command - Exécute une commande donnée dans le processus courant.
 * @command: La commande à exécuter.
 */
void execute_command(char *command)
{
char *argv[2];

argv[0] = command;
argv[1] = NULL;

if (execve(argv[0], argv, NULL) == -1)
{
perror(command);
exit(EXIT_FAILURE);
}
}

