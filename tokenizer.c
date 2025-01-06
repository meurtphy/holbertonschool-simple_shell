#include "shell.h"

/**
 * tokenize_command - Découpe une commande en tokens
 * @command: Commande à découper
 *
 * Return: Tableau de tokens ou NULL en cas d'erreur.
 */
char **tokenize_command(char *command)
{
    char **tokens = malloc(sizeof(char *) * 1024);
    char *token;
    size_t i = 0;

    if (!tokens)
        return (NULL);

    token = strtok(command, " \t\n");
    while (token)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return (tokens);
}

/**
 * free_tokens - Libère la mémoire des tokens
 * @tokens: Tableau de tokens
 */
void free_tokens(char **tokens)
{
    size_t i = 0;

    if (!tokens)
        return;

    while (tokens[i])
        free(tokens[i++]);

    free(tokens);
}
