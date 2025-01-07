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

if (getline(&line, &len, stdin) == -1)
{
if (line)
{
printf("Freeing memory at %p\n", (void *)line);
free(line);
line = NULL;
}
return (NULL);
}

printf("Allocated memory at %p in read_command\n", (void *)line);
line[strcspn(line, "\n")] = '\0';
return (line);
}

