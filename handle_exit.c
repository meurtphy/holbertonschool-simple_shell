#include "shell.h"

int handle_exit(char *command)
{
if (strncmp(command, "exit", 4) == 0 && (command[4] == '\0' || command[4] == ' '))
{
if (command[4] != '\0')
{
char *arg = command + 5;
int status = string_to_int(arg);

if (status == -1)
{
fprintf(stderr, "Invalid exit status: %s\n", arg);
return (0);
}

exit(status);
}

exit(0);
}
return (0);
}
