#include "shell.h"

/**
 * find_in_path - Recherche une commande dans le PATH
 * @command: Commande à rechercher
 *
 * Return: Chemin complet de la commande ou NULL si introuvable.
 */
char *find_in_path(char *command)
{
    char *path = getenv("PATH"), *path_copy, *dir, *full_path;
    struct stat st;

    if (!path)
        return (NULL);

    path_copy = strdup(path);
    dir = strtok(path_copy, ":");
    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", dir, command);

        if (stat(full_path, &st) == 0)
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
