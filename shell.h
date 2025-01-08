#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

void print_prompt(void);
char *resolve_path(char *command);
void fork_wait_exec(char *command);
void execute_command(char *command);
int handle_exit(char *command);

#endif
