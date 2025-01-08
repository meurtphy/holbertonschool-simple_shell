#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>


void print_prompt(void);
char *read_command(void);
void execute_command(char *command);
void fork_wait_exec(char *command);
void print_pid(void);
void print_ppid(void);


int _str_to_int(const char *str);
void exit_shell(char **args, char *command, char **history);
void cleanup_and_exit(char *command, char **history, int exit_code);

#endif
