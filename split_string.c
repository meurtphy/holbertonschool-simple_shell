#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str)
{
int count = 0;
char **result = NULL;
char *token = strtok(str, " ");

while (token != NULL)
{
result = realloc(result, sizeof(char *) * (count + 1));
if (result == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
result[count] = token;
count++;
token = strtok(NULL, " ");
}

result = realloc(result, sizeof(char *) * (count + 1));
result[count] = NULL;

return (result);
}

