#include "shell.h"

/**
 * main - Point d'entrée du shell.
 *
 * Return: Toujours 0.
 */
int main(void)
{
char *command;

while (1)
{
display_prompt();
command = read_command();
if (!command)
{
printf("\n");
break;
}

execute_command(command);
free(command);
}

return (0);
}

