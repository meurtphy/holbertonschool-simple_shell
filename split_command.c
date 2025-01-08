#include "shell.h"

char **split_command(char *command)
{
int bufsize = 64, i = 0;
char **argv = malloc(bufsize * sizeof(char *));
char *arg;

if (!argv)
exit(EXIT_FAILURE);

arg = strtok(command, " ");
while (arg)
{
argv[i++] = arg;
if (i >= bufsize)
{
bufsize += 64;
argv = realloc(argv, bufsize * sizeof(char *));
if (!argv)
exit(EXIT_FAILURE);
}
arg = strtok(NULL, " ");
}
argv[i] = NULL;
return (argv);
}
