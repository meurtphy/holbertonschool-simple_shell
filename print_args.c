#include "shell.h"

/**
 * print_args - Affiche les arguments passés en ligne de commande
 * @av: Tableau des arguments
 */
void print_args(char **av)
{
int i = 0;
while (av[i])
{
printf("Argument %d: %s\n", i, av[i]);
i++;
}
}

