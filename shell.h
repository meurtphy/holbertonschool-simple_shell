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
int execute_command(char **tokens, char **argv);
char *find_in_path(char *command);
char **tokenize_command(char *command);
void free_tokens(char **tokens);
int is_builtin(char **tokens, char **env);
int _strcmp(char *s1, char *s2);

#endif
