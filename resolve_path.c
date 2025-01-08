#include "shell.h"

char *resolve_path(char *command)
{
char *path = getenv("PATH");
char *path_copy;
char *dir;
char *full_path;

if (!command || command[0] == '\0')
return (NULL);

if (access(command, X_OK) == 0)
return (strdup(command));

if (!path)
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
