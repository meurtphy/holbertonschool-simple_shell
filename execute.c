#include "shell.h"

/**
 * execute_command - Exécute une commande externe
 * @tokens: Tableau de tokens
 * @argv: Tableau d'arguments
 *
 * Return: 0 si la commande est exécutée, -1 sinon.
 */
int execute_command(char **tokens, char **argv)
{
    pid_t pid;
    int status;
    char *cmd_path;

    cmd_path = find_in_path(tokens[0]); /* Recherche la commande */
    if (!cmd_path)
        return (-1);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(cmd_path);
        return (-1);
    }

    if (pid == 0) /* Processus enfant */
    {
        execve(cmd_path, tokens, environ);
        perror(argv[0]);
        free(cmd_path);
        exit(EXIT_FAILURE);
    }
    else /* Processus parent */
        wait(&status);

    free(cmd_path);
    return (0);
}
