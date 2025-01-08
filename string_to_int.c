#include "shell.h"

int string_to_int(char *str)
{
int i = 0, num = 0, sign = 1;

if (!str || str[0] == '\0')
return (-1);

if (str[i] == '-')
{
sign = -1;
i++;
}

while (str[i])
{
if (str[i] < '0' || str[i] > '9')
return (-1);

if (num > (INT_MAX - (str[i] - '0')) / 10)
return (-1);

num = num * 10 + (str[i] - '0');
i++;
}

return (num *sign);
}
