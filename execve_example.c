#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
char *const argv[] = {"/bin/ls", "-l", NULL};
char *const envp[] = {NULL};

printf("Before execve, this program will be replaced.\n");


if (execve("/bin/ls", argv, envp) == -1)
{
perror("execve failed");
exit(EXIT_FAILURE);
}


printf("This will not print if execve succeeds.\n");

return (0);
}

