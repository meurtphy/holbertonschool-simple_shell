#include "shell.h"

void handle_exit(char *command)

{
if (strcmp(command, "exit") == 0)
{
free(command);
exit(-1);
}
}