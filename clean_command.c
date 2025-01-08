#include "shell.h"

char *clean_command(char *command)
{
int i = 0, j = 0;
char *cleaned = malloc(strlen(command) + 1);

if (!cleaned)
return (NULL);

while (command[i])
{
if (!(command[i] == ' ' && (i == 0 || command[i - 1] == ' ')))
cleaned[j++] = command[i];
i++;
}

if (j > 0 && cleaned[j - 1] == ' ')
j--;

cleaned[j] = '\0';
return (cleaned);
}
