#include <stdio.h>
#include <stdlib.h>

int main() {
char *line = NULL;
size_t len = 0;
while (1) {
printf("$ ");
ssize_t nread = getline(&line, &len, stdin);

if (nread == -1)
{
printf("\nEnd of input (EOF)\n");
break;
}

printf("You entered: %s", line);
}

free(line);
return (0);
}

