#include "shell.h"

/**
 * main - Boucle principale du shell.
 * @argc: Nombre d'arguments.
 * @argv: Tableau des arguments.
 *
 * Return: 0 en cas de succès.
 */
int main(int argc, char **argv)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc; /* Supprime les warnings si argc n'est pas utilisé */

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Mode interactif */
            printf("$ ");

        nread = getline(&command, &len, stdin); /* Lire la commande */
        if (nread == -1) /* EOF (Ctrl+D) */
        {
            free(command);
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0'; /* Supprime le \n */
        if (strlen(command) == 0) /* Commande vide */
            continue;

        if (execute_command(command, argv) == -1)
            fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
    }

    free(command);
    return 0;
}
