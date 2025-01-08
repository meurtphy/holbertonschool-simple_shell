#include "shell.h"

int main(int argc, char **argv, char **env)
{
(void)argc;
(void)argv;

char *command = NULL, *cleaned_command = NULL;
size_t len = 0;
int is_interactive = isatty(STDIN_FILENO);

while (1)
{
if (is_interactive)
write(STDOUT_FILENO, "$ ", 2);

if (getline(&command, &len, stdin) == -1)
{
if (is_interactive)
write(STDOUT_FILENO, "\n", 1);
break;
}

command[strcspn(command, "\n")] = '\0';

if (strlen(command) == 0)
continue;

cleaned_command = clean_command(command);
if (!cleaned_command)
continue;

if (handle_exit(cleaned_command))
{
free(cleaned_command);
break;
}

fork_wait_exec(cleaned_command, env);
free(cleaned_command);
}

free(command);
return (0);
}
