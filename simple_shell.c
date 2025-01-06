#include "simple_shell.h"

/**
 * display_prompt - Affiche le prompt pour l'utilisateur.
 */
void display_prompt(void)
{
printf("#cisfun$ ");
}

/**
 * read_command - Lit la commande entrée par l'utilisateur.
 *
 * Return: La commande sous forme de chaînr
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
if (strlen(line) == 0 || line[0] == '\033')
{
free(line);
return (NULL);
}

return (line);
}

/**
 * execute_command - Exécute la commande entrée par l'utilisateur.
 * @line: La commande à exécuter.
 */
void execute_command(char *line)
{
pid_t child_pid;
int status;

if (strcmp(line, "exit") == 0) /* Gérer la commande `exit` */
{
handle_exit(line);
}

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
fprintf(stderr, "./shell: %s: No such file or directory\n", line);
exit(EXIT_FAILURE);
}
}
else /* Code du processus parent */
{
wait(&status); /* Attend la fin du processus enfant */
}
}

/**
 * handle_exit - Gère la sortie propre du shell.
 * @line: La commande à libérer.
 */
void handle_exit(char *line)
{
free(line);
printf("\n");
exit(0);
}

#include "simple_shell.h"

/**
 * main - Point d'entrée du shell.
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

if (!line) /* EOF ou Ctrl+D */
{
printf("\n");
break;
}

execute_command(line);
free(line);
}

return (0);
}



