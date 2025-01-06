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
    char *line = NULL, **tokens = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc; /* Pour éviter les warnings inutilisés */

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Affiche le prompt en mode interactif */
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&line, &len, stdin); /* Lire la commande */
        if (nread == -1) /* EOF ou erreur */
            break;

        line[nread - 1] = '\0'; /* Supprime le '\n' de la fin */
        tokens = tokenize_command(line); /* Découpe la commande */

        if (tokens && tokens[0]) /* Si une commande est saisie */
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
