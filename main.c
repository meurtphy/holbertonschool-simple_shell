#include "shell.h"

/**
 * main - Point d'entrée du shell
 * @argc: Nombre d'arguments
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès.
 */
int main(int argc, char **argv)
{
    char *line = NULL, **tokens = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Mode interactif */
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&line, &len, stdin);
        if (nread == -1) /* EOF ou erreur */
            break;

        line[nread - 1] = '\0'; /* Retirer le '\n' */
        tokens = tokenize_command(line); /* Découper la commande */

        if (tokens && tokens[0]) /* Si une commande est saisie */
        {
            if (is_builtin(tokens, environ) == 0) /* Commande interne */
                continue;

            if (execute_command(tokens, argv) == -1) /* Commande externe */
                fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
        }

        free_tokens(tokens);
    }

    free(line);
    return (0);
}
