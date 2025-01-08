#include "shell.h"

int handle_exit(char *command)
{
if (strcmp(command, "exit") == 0)
exit(0);

if (strncmp(command, "exit ", 5) == 0)
{
char *arg = command + 5;
char *endptr;
long status = strtol(arg, &endptr, 10);

if (*endptr != '\0' || status < 0)
{
fprintf(stderr, "./hsh: exit: Illegal number: %s\n", arg);
return (0);
}

exit((int)status);
}

return (0);
}
