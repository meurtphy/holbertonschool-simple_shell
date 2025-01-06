#include "shell.h"

int main(int argc, char **argv)
{
    char *command = NULL; /* Pointeur pour la commande */
    size_t len = 0;       /* Taille du buffer */
    ssize_t nread;

    (void)argc; /* Supprime les avertissements pour argc inutilisé */

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Mode interactif */
            printf("$ ");

        nread = getline(&command, &len, stdin); /* Lire la commande */
        if (nread == -1) /* Gestion de EOF (Ctrl+D) */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            free(command); /* Libérer la mémoire ici une seule fois */
            break;
        }

        command[strcspn(command, "\n")] = '\0'; /* Supprime le retour à la ligne */
        if (strlen(command) == 0) /* Commande vide */
            continue;

        if (execute_command(command, argv) == -1)
            fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
    }

    return 0;
}
