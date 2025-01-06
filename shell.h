#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* Prototypes */
int execute_command(char *command, char **argv);
char *find_command_in_path(char *command);

#endif /* SHELL_H */
