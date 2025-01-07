#include "shell.h"

/**
 * read_command - Lit une commande de l'utilisateur
 *
 * Return: La commande entrée par l'utilisateur
 */
char *read_command(void)
{
char *line = NULL;
size_t len = 0;

printf("$ ");
if (getline(&line, &len, stdin) == -1)
{
free(line);
return (NULL);
}

line[strcspn(line, "\n")] = '\0';
return (line);
}

