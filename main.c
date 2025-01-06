#include "shell.h"

/**
 * main - Point d'entrée du programme
 * @argc: Nombre d'arguments
 * @argv: Tableau des arguments
 *
 * Return: 0 en cas de succès, 1 sinon.
 */
int main(int argc, char **argv)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Mode interactif */
            printf("$ ");

        nread = getline(&command, &len, stdin); /* Lire la commande */
        if (nread == -1) /* EOF ou erreur */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0'; /* Supprimer '\n' */
        if (*command) /* Si la commande n'est pas vide */
        {
            if (execute_command(command, argv) == -1)
                fprintf(stderr, "%s: Command not found: %s\n", argv[0], command);
        }
    }

    free(command);
    return (0);
}
