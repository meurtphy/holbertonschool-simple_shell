#include "shell.h"

/**
 * display_prompt - Affiche le prompt pour l'utilisateur.
 */
void display_prompt(void)
{
if (isatty(STDIN_FILENO))
{

write(STDOUT_FILENO, "($) ", 4);

}
}

