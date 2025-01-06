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
    char *argv[2];
    struct stat st;

    argv[0] = command;
    argv[1] = NULL;

    if (stat(command, &st) != 0) /* Vérifie si le fichier existe */
    {
        fprintf(stderr, "./shell: %s: No such file or directory\n", command);
        return -1;
    }

    pid = fork();
    if (pid == -1) /* Gestion d'erreur de fork */
    {
        perror("fork");
        return -1;
    }

    if (pid == 0) /* Processus enfant */
    {
        if (execve(command, argv, environ) == -1)
        {
            perror(command);
            exit(EXIT_FAILURE);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attend que l'enfant termine */
    }

    return 0;
}
