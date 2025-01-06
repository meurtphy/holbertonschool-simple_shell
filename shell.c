#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/**
 * display_prompt - Affiche le prompt "$ ".
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

/**
 * execute_command - Exécute une commande en utilisant execve.
 * @command: La commande à exécuter.
 *
 * Retourne: 0 si la commande est exécutée avec succès, -1 sinon.
 */
int execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[] = {command, NULL}; /* Commande sans arguments */
    struct stat st;

    /* Vérifie si le fichier est accessible */
    if (stat(command, &st) != 0)
        return -1;

    pid = fork();
    if (pid == -1) /* Gestion d'erreur de fork */
    {
        perror("fork");
        return -1;
    }

    if (pid == 0) /* Processus enfant */
    {
        if (execve(command, argv, environ) == -1) /* Exécute la commande */
        {
            perror(command);
            exit(EXIT_FAILURE);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attend que l'enfant termine */
    }

    return 0;
}

/**
 * main - Boucle principale de l'interpréteur de commandes.
 *
 * Retourne: 0 en cas de succès.
 */
int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Vérifie si le mode est interactif */
            display_prompt();

        nread = getline(&command, &len, stdin); /* Lit l'entrée de l'utilisateur */
        if (nread == -1) /* Gestion de EOF (Ctrl+D) */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        /* Supprime le retour à la ligne de la commande */
        command[strcspn(command, "\n")] = '\0';

        /* Ignore les entrées vides */
        if (strlen(command) == 0)
            continue;

        /* Tente d'exécuter la commande */
        if (execute_command(command) == -1)
            fprintf(stderr, "./shell: %s: No such file or directory\n", command);
    }

    free(command); /* Libère la mémoire */
    return 0;
}
