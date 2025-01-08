#include "shell.h"

void fork_wait_exec(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
return;
}

if (pid == 0)
{
execute_command(command);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
}
}

