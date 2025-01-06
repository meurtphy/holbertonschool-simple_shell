#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
const int num_children = 5;
pid_t pid;
int status;


char *const argv[] = {"/bin/ls", "-l", "/tmp", NULL};
char *const envp[] = {NULL};

for (int i = 0; i < num_children; i++)
{
pid = fork();

if (pid < 0)
{
perror("fork failed");
exit(EXIT_FAILURE);
}

if (pid == 0)
{

printf("Child %d (PID: %d) executing ls -l /tmp\n", i + 1, getpid());
if (execve("/bin/ls", argv, envp) == -1)
{
perror("execve failed");
exit(EXIT_FAILURE);
}
}
else
{

printf("Parent (PID: %d) waiting for child %d (PID: %d) to finish\n", getpid(), i + 1, pid);
waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child %d (PID: %d) exited with status %d\n", i + 1, pid, WEXITSTATUS(status));
}
else
{
printf("Child %d (PID: %d) terminated abnormally\n", i + 1, pid);
}
}
}

printf("All child processes have completed.\n");
return (0);
}

