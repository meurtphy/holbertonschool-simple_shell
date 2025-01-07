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

fork_wait_exec(command);
free(command);
command = NULL;
}

if (command)
{
free(command);
command = NULL;
}

return (0);
}





