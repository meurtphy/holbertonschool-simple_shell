#include "shell.h"

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

int main(void)
{
char *command = NULL;
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

if (strlen(command) == 0)
{
free(command);
continue;
}

fork_wait_exec(command);
free(command);
}

return (0);
}
