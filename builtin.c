#include "shell.h"

/**
 * is_builtin - Vérifie si une commande est interne
 * @tokens: Tableau de tokens
 * @env: Environnement
 *
 * Return: 0 si une commande interne est exécutée, -1 sinon.
 */
int is_builtin(char **tokens, char **env)
{
    int i; /* Déclaration de la variable au début (conforme au C89) */

    if (_strcmp(tokens[0], "exit") == 0)
    {
        free_tokens(tokens);
        exit(0);
    }

    if (_strcmp(tokens[0], "env") == 0)
    {
        for (i = 0; env[i]; i++) /* Boucle corrigée pour C89 */
            printf("%s\n", env[i]);
        return (0);
    }

    return (-1);
}
