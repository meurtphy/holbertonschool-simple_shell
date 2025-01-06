#include "shell.h"

/**
 * execute_command - Exécute une commande
 * @command: Commande à exécuter
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, -1 sinon.
 */
int execute_command(char *command, char **argv)
{
    pid_t pid;
    int status;
    char *cmd_path;
    char *cmd[] = {NULL, NULL};

    cmd_path = find_command_in_path(command); /* Recherche dans le PATH */
    if (!cmd_path)
        return (-1); /* Commande non trouvée */

    cmd[0] = cmd_path; /* Construire l'argument pour execve */

    pid = fork(); /* Créer un processus enfant */
    if (pid == -1)
    {
        perror("fork");
        free(cmd_path);
        return (-1);
    }

    if (pid == 0) /* Enfant */
    {
        execve(cmd_path, cmd, environ); /* Exécuter la commande */
        perror(argv[0]); /* En cas d'échec */
        free(cmd_path);
        exit(EXIT_FAILURE);
    }
    else /* Parent */
        waitpid(pid, &status, 0); /* Attendre la fin de l'enfant */

    free(cmd_path);
    return (0);
}
