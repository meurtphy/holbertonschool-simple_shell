#include <stdio.h>
#include <limits.h>

/**
 * _str_to_int - Convertit une chaîne en entier.
 * @str: La chaîne à convertir.
 *
 * Return: L'entier converti ou -1 en cas d'erreur
 */
int _str_to_int(const char *str)
{
int i = 0;
unsigned long result = 0;
int is_negative = 0;

if (!str || *str == '\0')
return (-1);


while (str[i] == ' ' || str[i] == '\t')
i++;


if (str[i] == '-')
{
is_negative = 1;
i++;
}
else if (str[i] == '+')
{
i++;
}


while (str[i])
{
if (str[i] < '0' || str[i] > '9')
return (-1);

result = result * 10 + (str[i] - '0');
if (result > (unsigned long)(is_negative ? INT_MAX + 1UL : INT_MAX))
return (-1);

i++;
}


if (is_negative)
return (-((int)result));

return ((int)result);
}

