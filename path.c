#include "shell.h"

/**
 * find_command_in_path - Recherche le chemin complet d'une commande
 * @command: Commande à rechercher
 *
 * Return: Le chemin absolu de la commande, ou NULL si non trouvée.
 */
char *find_command_in_path(char *command)
{
    char *path = getenv("PATH");
    char *path_copy, *dir, *full_path;
    struct stat st;

    if (!path)
        return (NULL);

    path_copy = strdup(path); /* Copie pour strtok */
    if (!path_copy)
        return (NULL);

    dir = strtok(path_copy, ":");
    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2); /* dir + '/' + command */
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        sprintf(full_path, "%s/%s", dir, command);
        if (stat(full_path, &st) == 0) /* Commande trouvée */
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path); /* Essayer un autre répertoire */
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
