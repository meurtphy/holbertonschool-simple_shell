#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Déclaration de la variable globale environ */
extern char **environ;

/* Prototypes des fonctions */
char *read_line(void);
char **parse_line(char *line);
void execute_command(char **args);
void free_args(char **args);

#endif /* SHELL_H */
