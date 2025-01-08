#include "shell.h"

int string_to_int(char *str, int *error)
{
int i = 0, num = 0, sign = 1;

while (str[i] == ' ')
i++;

if (str[i] == '-' || str[i] == '+')
{
if (str[i] == '-')
sign = -1;
i++;
}

while (str[i] != '\0')
{
if (str[i] < '0' || str[i] > '9')
{
*error = 1;
return (0);
}
num = num * 10 + (str[i] - '0');
i++;
}

return (num * sign);
}

char **tokenize_command(char *command)
{
char **args = malloc(sizeof(char *) * 64);
char *token;
int i = 0;

if (!args)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(command, " ");
while (token != NULL)
{
args[i++] = strdup(token);
token = strtok(NULL, " ");
}
args[i] = NULL;

return (args);
}

void free_args(char **args)
{
int i = 0;

while (args[i])
free(args[i++]);
free(args);
}

