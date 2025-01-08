#include "shell.h"

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

int main(void)
{
char *command = NULL;
size_t len = 0;
int is_interactive = isatty(STDIN_FILENO);

while (1)
{
if (is_interactive)
print_prompt();

if (getline(&command, &len, stdin) == -1)
{
if (is_interactive)
putchar('\n');
break;
}

command[strcspn(command, "\n")] = '\0';

if (strlen(command) == 0)
continue;

if (handle_exit(command))
break;

fork_wait_exec(command);
}

free(command);
return (0);
}
