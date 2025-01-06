#include "simple_shell.h"

/**
 * display_prompt - Affiche le prompt.
 */
void display_prompt(void)
{
printf("$ ");
}

/**
 * read_command - Lit l'entrée utilisateur.
 *
 * Return: La commande entrée par l'utilisateur
 */
char *read_command(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
return (NULL);
}

line[strcspn(line, "\n")] = '\0';
return (line);
}

/**
 * execute_command - Exécute une commande via execve.
 * @line: La commande à exécuter.
 */
void execute_command(char *line)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("Erreur avec fork");
return;
}

if (child_pid == 0)
{
char *argv[] = {line, NULL};
if (execve(line, argv, environ) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}

/**
 * handle_exit - Libère les ressources et quitte le shell.
 * @line: La commande à libérer.
 */
void handle_exit(char *line)
{
free(line); /* Libère la mémoire */
printf("\nFin du shell.\n");
exit(0);
}

/**
 * main - Boucle principale du shell simple.
 *
 * Return: Toujours 0.
 */
int main(void)
{
char *line;

while (1)
{
display_prompt();
line = read_command();

if (!line)
handle_exit(NULL);

if (strlen(line) == 0)
{
free(line);
continue;
}

execute_command(line);
free(line);
}

return (0);
}

