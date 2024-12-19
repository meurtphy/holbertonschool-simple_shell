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

return result;
}

int main(void)
{
char input[] = "This is a test string";
char **words;
int i;

words = split_string(input);
if (words == NULL)
{
printf("No words found.\n");
return (1);
}

printf("Words in the string:\n");
for (i = 0; words[i] != NULL; i++)
{
printf("%s\n", words[i]);
}

free(words);
return (0);
}

