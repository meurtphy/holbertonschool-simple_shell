#include "shell.h"

/**
 * main - Point d'entrée du shell
 * @argc: Nombre d'arguments
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, 1 sinon.
 */
int main(int argc, char **argv)
{
    char *line = NULL, **tokens;
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

        line[nread - 1] = '\0'; /* Supprimer le '\n' */
        tokens = tokenize_command(line);

        if (tokens && tokens[0]) /* Exécuter si la commande n'est pas vide */
        {
            if (strcmp(tokens[0], "exit") == 0) /* Commande "exit" */
                break;

            if (execute_command(tokens, argv) == -1) /* Commande non trouvée */
                fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
        }

        free_tokens(tokens);
    }

    free(line);
    return (0);
}
