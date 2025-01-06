#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
char *line = NULL;
size_t len = 0;
pid_t pid;
int status;

while (1)
{
printf("simple-shell> ");
ssize_t nread = getline(&line, &len, stdin);

if (nread == -1)
{
printf("\nExiting shell.\n");
break;
}


line[strcspn(line, "\n")] = '\0';


pid = fork();
if (pid < 0)
{
perror("fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{

char *const argv[] = {line, NULL};
if (execve(line, argv, NULL) == -1) {
perror("execve failed");
exit(EXIT_FAILURE);
}
}
else
{

waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child exited with status %d\n", WEXITSTATUS(status));
}
else
{
printf("Child terminated abnormally.\n");
}
}
}

free(line);
return (0);
}

