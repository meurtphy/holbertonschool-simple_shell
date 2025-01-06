#include <stdio.h>  /* Pour sprintf */
#include <string.h> /* Pour strtok et strlen */
#include <sys/stat.h> /* Pour stat */
#include <stdlib.h> /* Pour malloc et free */

/**
 * find_command_in_path - Recherche le chemin complet d'une commande dans le PATH.
 * @command: La commande à rechercher.
 *
 * Return: Le chemin absolu de la commande, ou NULL si elle n'est pas trouvée.
 */
char *find_command_in_path(char *command)
{
    char *path = getenv("PATH"); /* Récupère le PATH */
    char *path_copy, *dir, *full_path;
    struct stat st;

    if (!path) /* Si PATH n'existe pas */
        return NULL;

    path_copy = strdup(path); /* Copie PATH pour strtok */
    dir = strtok(path_copy, ":"); /* Divise PATH en répertoires */

    while (dir != NULL)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2); /* Taille = dir + / + command + \0 */
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }

        sprintf(full_path, "%s/%s", dir, command); /* Construit le chemin */
        if (stat(full_path, &st) == 0) /* Vérifie si le fichier existe */
        {
            free(path_copy);
            return full_path; /* Retourne le chemin complet */
        }

        free(full_path); /* Libère la mémoire pour ce chemin */
        dir = strtok(NULL, ":"); /* Passe au répertoire suivant */
    }

    free(path_copy);
    return NULL; /* Commande non trouvée */
}
