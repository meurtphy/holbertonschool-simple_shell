#include "shell.h"

extern char **environ; /* Déclare environ */

/**
 * execute_command - Exécute une commande.
 * @command: Commande à exécuter.
 * @argv: Tableau des arguments.
 *
 * Return: 0 si la commande a été exécutée, -1 sinon.
 */
int execute_command(char *command, char **argv)
{
    pid_t pid;
    int status;
    char *cmd[2]; /* Tableau pour la commande */
    struct stat st;

    cmd[0] = command; /* Affecte la commande */
    cmd[1] = NULL; /* Termine le tableau */

    if (stat(command, &st) != 0) /* Vérifie si le fichier existe */
    {
        fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
        return -1;
    }

    pid = fork();
    if (pid == -1) /* Échec de fork */
    {
        perror(argv[0]);
        return -1;
    }

    if (pid == 0) /* Processus enfant */
    {
        if (execve(command, cmd, environ) == -1)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attend que l'enfant termine */
    }

    return 0;
}
