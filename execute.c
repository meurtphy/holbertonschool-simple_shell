#include "shell.h"

/**
 * execute_command - Exécute une commande
 * @tokens: Tableau de tokens
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, -1 sinon.
 */
int execute_command(char **tokens, char **argv)
{
    pid_t pid;
    int status;
    char *cmd_path;

    cmd_path = find_in_path(tokens[0]);
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
