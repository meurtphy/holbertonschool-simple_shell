#include "shell.h"

/**
 * main - Point d'entrée du shell.
 * @argc: Nombre d'arguments (non utilisé).
 * @argv: Tableau des arguments (argv[0] utilisé pour les erreurs).
 *
 * Return: 0 en cas de succès, 1 en cas d'échec.
 */
int main(int argc, char **argv)
{
char *command;

(void)argc;
(void)argv;

while (1)
{
if (isatty(STDIN_FILENO))
display_prompt();

command = read_command();

if (!command)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}

if (strlen(command) > 0)
{
execute_command(command);
}

free(command);
}
return (0);
}

