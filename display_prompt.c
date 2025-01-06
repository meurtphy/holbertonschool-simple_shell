#include "shell.h"

/**
 * display_prompt - Affiche le prompt pour l'utilisateur.
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout); /* S'assurer que le prompt est affiché immédiatement */
}
