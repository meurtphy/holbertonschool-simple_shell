#include "shell.h"

int handle_exit(char *command)
{
if (strncmp(command, "exit", 4) == 0 && (command[4] == '\0' || command[4] == ' '))
{
if (command[4] != '\0')
{
char *arg = command + 5;
int status = string_to_int(arg);
if (status == -1)
{
fprintf(stderr, "Invalid exit status: %s\n", arg);
return (0);
}
exit(status);
}
exit(0);
}
return (0);
}
#include "shell.h"

int string_to_int(char *str)
{
    int i = 0, num = 0, sign = 1;

    while (str[i] == ' ')
        i++;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    if (str[i] < '0' || str[i] > '9')
        return (-1);

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    while (str[i] == ' ')
        i++;

    if (str[i] != '\0')
        return (-1);

    return (num * sign);
}
