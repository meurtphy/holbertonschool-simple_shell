#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *line);
void handle_fork(char *line);

/**
 * main - Main loop of the simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

while (1)
{
printf("$ ");
nread = getline(&line, &len, stdin);

if (nread == -1)
{
printf("\nFin du shell.\n");
break;
}

line[strcspn(line, "\n")] = '\0';

if (strlen(line) == 0)
continue;

handle_fork(line);
}

free(line);
return (0);
}

/**
 * handle_fork - Handles the forking process
 * @line: The command line input
 */
void handle_fork(char *line)
{
pid_t child_pid;
int status;

child_pid = fork();

if (child_pid == -1)
{
perror("Erreur avec fork");
return;
}

if (child_pid == 0)
{
execute_command(line);
}
else
{
wait(&status);
}
}

/**
 * execute_command - Executes a command
 * @line: The command line input
 */
void execute_command(char *line)
{
char *argv[] = {line, NULL};

if (execve(line, argv, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}

