#include "shell.h"

char *read_command(void)
{
char *line = NULL;
size_t len = 0;

if (getline(&line, &len, stdin) == -1)
{
if (isatty(STDIN_FILENO))
putchar('\n');
if (line)
free(line);
return (NULL);
}

line[strcspn(line, "\n")] = '\0';
return (line);
}
