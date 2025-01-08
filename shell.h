#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void fork_wait_exec(char *command, char **env);
char *resolve_path(char *command);
int handle_exit(char *command);
char *clean_command(char *command);

#endif
