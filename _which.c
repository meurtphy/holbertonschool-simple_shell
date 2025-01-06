#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * find_in_path - Searches for a file in the directories listed in PATH.
 * @filename: The name of the file to find.
 *
 * Return: 1 if the file is found, 0 otherwise.
 */
int find_in_path(const char *filename)
{
char *path_env = getenv("PATH");
if (path_env == NULL) {
fprintf(stderr, "PATH environment variable not found.\n");
return (0);
}

char *path = strdup(path_env);
if (path == NULL) {
perror("strdup failed");
return (0);
}

char *dir = strtok(path, ":");
struct stat st;

while (dir != NULL)
{
char filepath[4096];
snprintf(filepath, sizeof(filepath), "%s/%s", dir, filename);

if (stat(filepath, &st) == 0)
{
printf("%s\n", filepath);
free(path);
return (1);
}

dir = strtok(NULL, ":");
}

free(path);
return (0);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
if (argc < 2)
{
printf("Usage: %s filename ...\n", argv[0]);
return (1);
}

for (int i = 1; i < argc; i++)
{
printf("%s: ", argv[i]);
if (!find_in_path(argv[i]))
{
printf("NOT FOUND\n");
}
}

return (0);
}

