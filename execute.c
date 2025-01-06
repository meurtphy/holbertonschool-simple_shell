#include "shell.h"
#include <sys/wait.h> /* Pour waitpid */

extern char **environ; /* Déclaration explicite de environ */

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
    char *cmd_path;
    char *cmd[2];
    struct stat st;

    if (stat(command, &st) == 0) /* Commande avec chemin absolu */
        cmd_path = strdup(command);
    else /* Recherche dans le PATH */
        cmd_path = find_command_in_path(command);

    if (!cmd_path) /* Commande introuvable */
    {
        fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
        return -1;
    }

    cmd[0] = cmd_path;
    cmd[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror(argv[0]);
        free(cmd_path);
        return -1;
    }

    if (pid == 0) /* Processus enfant */
    {
        if (execve(cmd_path, cmd, environ) == -1)
        {
            perror(argv[0]);
            free(cmd_path);
            exit(EXIT_FAILURE);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attend que l'enfant termine */
    }

    free(cmd_path);
    return 0;
}
