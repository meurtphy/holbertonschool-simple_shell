#include "shell.h"

/**
 * print_error - Affiche un message d'erreur formaté.
 * @program: Le nom du programme (argv[0]).
 * @command: La commande ayant échoué.
 */
void print_error(char *program, char *command)
{
fprintf(stderr, "%s: %s: No such file or directory\n", program, command);
}

