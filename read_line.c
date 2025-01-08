#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_command - Lit une ligne de commande depuis l'entrée standard.
 *
 * Retourne :
 *   - Une chaîne de caractères contenant la commande sans le saut de ligne.
 *   - NULL si une erreur survient ou si EOF est atteint.
 */

char *read_command(void)
{
char *line = NULL;
size_t len = 0;

if (getline(&line, &len, stdin) == -1)
{
if (line)
free(line);
return (NULL);
}


line[strcspn(line, "\n")] = '\0';
line = trim_spaces(line);

return (line);
}
