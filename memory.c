#include "shell.h"

/**
 * free_args - Libère un tableau d'arguments.
 * @args: Le tableau d'arguments.
 */
void free_args(char **args)
{
free(args);
}
