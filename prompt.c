#include "shell.h"

/**
 * display_prompt - Affiche le prompt "$ ".
 */
void display_prompt(void)
{
    printf("$ ");
    fflush(stdout);
}

/**
 * read_command - Lit la commande entrée par l'utilisateur.
 *
 * Return: La commande saisie (doit être libérée après usage).
 */
char *read_command(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return NULL;
    }

    /* Supprime le retour à la ligne */
    line[strcspn(line, "\n")] = '\0';
    return line;
}
