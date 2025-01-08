#include "shell.h"
#include <sys/stat.h>
#include <unistd.h>

char *find_command(char *command)
{
char *path = getenv("PATH");
char *path_copy, *token, *full_path;
struct stat buffer;

if (stat(command, &buffer) == 0)
return strdup(command);

if (!path)
return (NULL);

path_copy = strdup(path);
if (!path_copy)
return (NULL);

token = strtok(path_copy, ":");
while (token)
{
full_path = malloc(strlen(token) + strlen(command) + 2);
if (!full_path)
{
free(path_copy);
return (NULL);
}
sprintf(full_path, "%s/%s", token, command);

if (stat(full_path, &buffer) == 0)
{
free(path_copy);
return (full_path);
}

free(full_path);
token = strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}
