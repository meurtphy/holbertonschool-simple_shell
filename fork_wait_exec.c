#include "shell.h"

void fork_wait_exec(char *command)
{
int status;
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("Erreur de fork");
return;
}

if (child_pid == 0)
{
execute_command(command);
_exit(EXIT_FAILURE);
}
else
{
if (wait(&status) == -1)
{
perror("Erreur de wait");
}
}
}

