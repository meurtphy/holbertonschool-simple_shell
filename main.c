#include "shell.h"

int main(void)
{
char *command = NULL;
char **args = NULL;
int is_interactive = isatty(STDIN_FILENO);

while (1)
{
if (is_interactive)
print_prompt();

command = read_command();
if (!command)
{
if (is_interactive)
putchar('\n');
break;
}

args = tokenize_command(command);
if (args == NULL || args[0] == NULL)
{
free(command);
free_args(args);
continue;
}

if (strcmp(args[0], "exit") == 0)
{
handle_exit(args);
}
else
{
fork_wait_exec(args[0]);
}

free(command);
free_args(args);
}

return (0);
}

