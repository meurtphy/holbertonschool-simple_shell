#include "shell.h"

void handle_exit(char **args)
{
int error = 0;
int exit_code = 0;

if (args[1] == NULL)
{
exit(0);
}

exit_code = string_to_int(args[1], &error);
if (error)
{
fprintf(stderr, "exit: Illegal number: %s\n", args[1]);
return;
}

exit(exit_code);
}

