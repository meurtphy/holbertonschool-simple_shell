#include "shell.h"

/**
 * get_command - Lit une commande depuis l'entrée standard
 *
 * Return: Chaîne contenant la commande ou NULL en cas d'erreur/EOF.
 */
char *get_command(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
