#include "shell.h"

/**
 * main - Point d'entrée du shell
 * @argc: Nombre d'arguments
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, ou 1 sinon.
 */
int main(int argc, char **argv)
{
    char *command = NULL, **tokens = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");

        nread = getline(&command, &len, stdin);
        if (nread == -1) /* EOF ou erreur */
            break;

        command[strcspn(command, "\n")] = '\0'; /* Retirer '\n' */
        tokens = tokenize_command(command); /* Découper la commande */
        if (tokens && tokens[0])
        {
            if (strcmp(tokens[0], "exit") == 0)
                break; /* Quitter si la commande est "exit" */

            if (execute_command(tokens, argv) == -1)
                fprintf(stderr, "%s: Command not found: %s\n", argv[0], tokens[0]);
        }

        free_tokens(tokens); /* Libérer les tokens */
    }

    free(command);
    return (0);
}
