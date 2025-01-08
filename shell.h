#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

void fork_wait_exec(char *command, char **env, char *prog_name);
char *resolve_path(char *command);
int handle_exit(char *command);
int string_to_int(char *str); /* Déclaration ajoutée */
char **split_command(char *command); /* Pour éviter l'erreur implicite */
void print_env(void); /* Pour éviter l'erreur implicite */
char *clean_command(char *command); /* Pour éviter l'erreur implicite */

#endif
