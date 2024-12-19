#include <stdio.h>
#include <unistd.h>

int main()
{

pid_t parent_pid = getppid();
printf("Le PID du processus parent est : %d\n", parent_pid);
return (0);
}