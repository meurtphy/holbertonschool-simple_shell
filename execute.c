#include "shell.h"

extern char **environ; /* Déclare environ */

/**
 * execute_command - Exécute une commande en utilisant execve.
 * @command: La commande à exécuter.
 *
 * Return: 0 si la commande est exécutée avec succès, -1 sinon.
 */
int execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[2]; /* Tableau pour stocker la commande */
    struct stat st; /* Déclaration déplacée ici */

    argv[0] = command; /* Initialise le tableau */
    argv[1] = NULL;

    /* Vérifie si le fichier est accessible */
    if (stat(command, &st) != 0)
        return -1;

    pid = fork();
    if (pid == -1) /* Gestion d'erreur de fork */
    {
        perror("fork");
        return -1;
    }

    if (pid == 0) /* Processus enfant */
    {
        if (execve(command, argv, environ) == -1) /* Exécute la commande */
        {
            perror(command);
            exit(EXIT_FAILURE);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attend la fin du processus enfant */
    }

    return 0;
}
