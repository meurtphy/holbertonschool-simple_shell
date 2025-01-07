#include "shell.h"

/**
 * print_pid - Affiche le PID du processus courant
 */
void print_pid(void)
{
printf("Mon PID est : %u\n", getpid());
}

/**
 * print_ppid - Affiche le PID du parent
 */
void print_ppid(void)
{
printf("Le PID du parent est : %u\n", getppid());
}

