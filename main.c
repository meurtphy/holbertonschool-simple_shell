#include "shell.h"

/**
 * main - Boucle principale de l'interpréteur.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command = NULL;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Mode interactif */
            display_prompt();

        command = read_command(); /* Lit l'entrée utilisateur */
        if (!command) /* Gestion de EOF (Ctrl+D) */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        if (strlen(command) > 0) /* Ignore les lignes vides */
        {
            if (execute_command(command) == -1)
                fprintf(stderr, "./simple_shell: %s: No such file or directory\n", command);
        }

        free(command);
    }

    return 0;
}
