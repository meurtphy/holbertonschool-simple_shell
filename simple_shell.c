#include "shell.h"

/**
 * main - Point d'entrée du shell.
 *
 * Return: Toujours 0.
 */
int main(void)
{
char *line;
char **args;

while (1)
{
printf("#cisfun$ ");
line = read_line();

if (!line)
{
printf("\n");
break;
}

args = parse_line(line);
execute_command(args);
free_args(args);
}

return (0);
}
