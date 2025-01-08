#include "shell.h"

char *resolve_path(char *command)
{
char *path = getenv("PATH");
char *path_copy = NULL;
char *dir = NULL;
char *full_path = NULL;

if (!path || !command || command[0] == '\0')
return (NULL);

path_copy = strdup(path);
if (!path_copy)
return (NULL);

dir = strtok(path_copy, ":");
while (dir)
{
full_path = malloc(strlen(dir) + strlen(command) + 2);
if (!full_path)
{
free(path_copy);
return (NULL);
}
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, X_OK) == 0)
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
