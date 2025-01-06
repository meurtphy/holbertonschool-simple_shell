#include "shell.h"

/**
 * parse_line - Découpe une ligne en tokens.
 * @line: La ligne à découper.
 *
 * Return: Un tableau de chaînes (tokens).
 */
char **parse_line(char *line)
{
size_t bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " ");
while (token != NULL)
{
tokens[i++] = token;

if (i >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " ");
}
tokens[i] = NULL;

return (tokens);
}

