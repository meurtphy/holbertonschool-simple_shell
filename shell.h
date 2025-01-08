#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void print_prompt(void);
char *read_command(void);
void execute_command(char *command);
void fork_wait_exec(char *command);
char *resolve_path(char *command);

#endif
