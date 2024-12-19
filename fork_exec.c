#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - Crée un processus enfant pour exécuter /bin/ls
 *
 * Return: Toujours 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/", NULL};

    child_pid = fork(); // Crée un processus enfant

    if (child_pid == -1)
    {
        perror("Erreur avec fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) // Code exécuté par le processus enfant
    {
        printf("Processus enfant : PID = %d\n", getpid());
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Erreur avec execve");
            exit(EXIT_FAILURE);
        }
    }
    else // Code exécuté par le processus parent
    {
        printf("Processus parent : PID = %d, Enfant PID = %d\n", getpid(), child_pid);
        wait(&status); // Attente de la fin du processus enfant
        printf("Processus enfant terminé\n");
    }

    return (0);
}
