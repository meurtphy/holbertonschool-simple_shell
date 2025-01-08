#include "shell.h"

int handle_exit(char *command)
{
if (strcmp(command, "exit") == 0)
return (1);

if (strncmp(command, "exit ", 5) == 0)
{
char *arg = command + 5;
int status = atoi(arg);

if (status < 0 && !isdigit(arg[0]))
{
fprintf(stderr, "./hsh: exit: Illegal number: %s\n", arg);
return (0);
}

exit(status);
}

return (0);
}
