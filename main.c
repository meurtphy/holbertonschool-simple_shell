#include "shell.h"

int main(void)
{
char *command = NULL;

while (1)
{
print_prompt();
command = read_command();

if (!command)
{
putchar('\n');
break;
}


if (strlen(command) == 0 || strchr(command, '[') != NULL)
{
free(command);
continue;
}

fork_wait_exec(command);
free(command);
command = NULL;
}

if (command)
free(command);

return (0);
}

