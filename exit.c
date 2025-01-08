#include "shell.h"

int handle_exit(char *command)
{
if (strcmp(command, "exit") == 0)
{
free(command);
exit(0);
}
return (0);
}

