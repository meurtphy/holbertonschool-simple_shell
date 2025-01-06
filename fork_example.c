#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
pid_t pid;

printf("Before fork: PID = %d\n", getpid());

pid = fork();

if (pid < 0)
{

perror("fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{

printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
}
else
{

printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
}


printf("Process PID = %d continues execution here.\n", getpid());

return (0);
}

