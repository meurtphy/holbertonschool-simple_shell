#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Boucle principale du shell simple
 *
 * Return: Toujours 0.
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
pid_t child_pid;
int status;

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

child_pid = fork();

if (child_pid == -1)
{
perror("Erreur avec fork");
continue;
}

if (child_pid == 0)
{
char *argv[] = {line, NULL};
if (execve(line, argv, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}

free(line);
return (0);
}
