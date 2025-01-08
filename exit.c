#include "shell.h"

/**
 * exit_shell - Gère la commande exit, nettoie et quitte le shell.
 * @args: Les arguments passés à la commande.
 * @command: La commande allouée dynamiquement.
 * @history: Tableau de commandes précédentes (facultatif).
 */
void exit_shell(char **args, char *command, char **history)
{
    int exit_code = 0;

    if (args[1]) // Vérifie s'il y a des arguments
    {
        if (args[2]) // Trop d'arguments
        {
            fprintf(stderr, "exit: too many arguments\n");
            return; // Ne quitte pas le shell
        }

        exit_code = _str_to_int(args[1]);
        if (exit_code == -1) // Erreur de conversion
        {
            fprintf(stderr, "exit: %s: numeric argument required\n", args[1]);
            cleanup_and_exit(command, history, 2); // Code d'erreur 2
        }
    }

    cleanup_and_exit(command, history, exit_code); // Quitte avec le code converti ou 0
}

/**
 * cleanup_and_exit - Nettoie les ressources et quitte le programme.
 * @command: La commande actuellement allouée dynamiquement.
 * @history: Tableau de commandes précédentes (facultatif).
 * @exit_code: Code de sortie.
 */
void cleanup_and_exit(char *command, char **history, int exit_code)
{
int i;

if (command)
free(command);

if (history)
{
for (i = 0; history[i] != NULL; i++)
free(history[i]);
free(history);
}

exit(exit_code);
}

