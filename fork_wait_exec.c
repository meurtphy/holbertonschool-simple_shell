#include "shell.h"

void fork_wait_exec(char *input)
{
char *command;


command = strtok(input, " ");
while (command != NULL)
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


command = strtok(NULL, " ");
}
}

