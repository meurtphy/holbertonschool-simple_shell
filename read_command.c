#include "shell.h"

/**
 * read_command - Lit une commande entrée par l'utilisateur.
 *
 * Return: La commande saisie, ou NULL en cas d'erreur ou EOF.
 */
char *read_command(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
return (NULL);
}

line[strcspn(line, "\n")] = '\0';
return (line);
}



