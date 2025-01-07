main.c
char *command;
Un pointeur command de type char * est déclaré. Il stockera l'adresse d'une chaîne de caractères contenant la commande saisie par l'utilisateur.

boucle infinie
while (1)

Afficher l'invite de commande :

print_prompt();

command = read_command();
La fonction read_command lit l'entrée utilisateur (probablement depuis le clavier) et retourne une chaîne de caractères. Cette chaîne est stockée dans le pointeur command.

if (!command)
{
    putchar('\n');
    break;
}
Si command est NULL (échec de read_command, ou l'utilisateur a entré une commande invalide), le programme :
Affiche un saut de ligne (putchar('\n')).
Quitte la boucle avec break.

fork_wait_exec(command);
Cette fonction semble :
Créer un processus enfant (probablement avec fork()).
Dans ce processus enfant, exécuter la commande avec une fonction comme execvp.
Dans le processus parent, attendre la fin de l'exécution du processus enfant (wait()).

et ensuite pour finir on free(command);

Libère la mémoire allouée pour stocker la chaîne de caractères contenant la commande. Cela évite une fuite de mémoire.

Résumé de main.c:
Ce programme implémente un mini-shell interactif. À chaque itération :

Il affiche une invite de commande.
Lit une commande utilisateur.
Exécute cette commande dans un processus enfant.
Attend la fin du processus enfant.
Libère les ressources avant de passer à l'itération suivante.
Si l'utilisateur entre une commande invalide (ou que read_command échoue), le programme termine proprement.

/////////////////////////
cisfun

Son rôle est d’afficher une invite de commande (#cisfun$ ) si les conditions sont remplies.

if (isatty(STDIN_FILENO))
La fonction isatty vérifie si le fichier donné (ici, STDIN_FILENO, c'est-à-dire l'entrée standard) correspond à un terminal interactif (comme un terminal physique ou un émulateur de terminal).
Si l'entrée standard est connectée à un terminal (et non à un fichier ou une redirection), la condition est vraie.
Cela permet d'afficher l'invite uniquement lorsque le programme est exécuté de manière interactive dans un terminal.

write(STDOUT_FILENO, "#cisfun$ ", 9);
La fonction write est utilisée pour écrire directement dans la sortie standard (STDOUT_FILENO).
"#cisfun$ " : Le texte de l'invite de commande.
9 : Le nombre de caractères à écrire (y compris l'espace et le $).
Cette ligne affiche l'invite de commande dans le terminal si l'entrée standard est interactive.

Résumé de utilis.c :
La fonction print_prompt est une composante d'un shell interactif. Elle permet :

D'afficher l'invite de commande (#cisfun$ ) uniquement lorsque le shell est utilisé dans un terminal interactif.
De ne rien afficher dans des cas non interactifs (par exemple, lors de l'exécution de scripts ou de commandes redirigées).
Cela garantit que l'invite de commande ne perturbe pas les flux d'entrée/sortie non interactifs.

/////////////////////////
Nom : read_command
Rôle : Lire une commande entrée par l'utilisateur via l'entrée standard (clavier).
Retour : La commande saisie sous forme de chaîne de caractères.
char *line = NULL;
size_t len = 0;
line :
Un pointeur de type char * initialisé à NULL. Ce pointeur servira à stocker la ligne de commande lue.
len :
Une variable de type size_t initialisée à 0. Elle stockera la taille du buffer que getline alloue dynamiquement.

Affichage de l'invite de commande :
c
Copier le code
printf("$ ");
Affiche une invite de commande ($ ) pour signaler à l'utilisateur qu'il peut entrer une commande

if (getline(&line, &len, stdin) == -1)
getline :
Lit une ligne depuis l'entrée standard (stdin) et stocke la chaîne dans le pointeur line.
Alloue dynamiquement la mémoire si nécessaire et ajuste la taille du buffer line selon len.
Retourne :
Le nombre de caractères lus, ou
-1 en cas d'erreur ou si l'utilisateur entre un signal EOF (Ctrl+D sous Unix/Linux).
Si getline retourne -1 :
Libère la mémoire allouée pour line avec free(line) (pour éviter les fuites de mémoire).
Retourne NULL pour indiquer une erreur ou une fin de saisie.

Résumé de readline.c:
La fonction read_command permet de lire une commande entrée par l'utilisateur de manière robuste et dynamique. Elle :

Affiche une invite pour inciter l'utilisateur à entrer une commande.
Utilise getline pour gérer efficacement la mémoire et lire l'entrée.
Supprime le caractère de nouvelle ligne ajouté automatiquement par getline.
Retourne la commande sous forme de chaîne de caractères prête à être interprétée ou exécutée.
Si une erreur ou un EOF survient, la fonction retourne NULL pour indiquer l'échec.
////////////////////////
Résumé pid_ppid.c:
Ces deux fonctions permettent d'afficher des informations essentielles sur les processus dans un shell ou un programme.

print_pid :
Utilisée pour afficher l'identifiant du processus en cours.
print_ppid :
Utile pour connaître le processus parent (par exemple, le shell ou un autre programme qui a exécuté ce processus).
Ces fonctions sont particulièrement utiles pour le débogage ou pour comprendre la hiérarchie des processus dans un environnement multi-processus.

///////////////////////
Si pid == 0, le code est exécuté dans le processus enfant :
execute_command(command) :
Une fonction (probablement définie dans shell.h) qui exécute la commande spécifiée.
Peut utiliser des fonctions système comme execvp pour exécuter des commandes.
exit(0) :
Termine proprement le processus enfant une fois la commande exécutée.
Si pid == 0, le code est exécuté dans le processus enfant :
execute_command(command) :
Une fonction (probablement définie dans shell.h) qui exécute la commande spécifiée.
Peut utiliser des fonctions système comme execvp pour exécuter des commandes.
exit(0) :
Termine proprement le processus enfant une fois la commande exécutée.

Résumé fork_wait_exercice.c:
La fonction fork_wait_exec implémente une étape clé d'un shell interactif :

Elle permet d'exécuter une commande en créant un processus enfant.
Le processus parent attend que le processus enfant termine avant de continuer.
Cette séparation est essentielle dans un shell, car elle permet :

De maintenir le shell actif tout en exécutant des commandes utilisateur dans des processus séparés.
De gérer correctement l'exécution et la terminaison des processus enfants.
/////////////////////////

Rôle global :
Préparer les arguments pour exécuter une commande.
Utiliser execve pour remplacer le processus courant par le programme spécifié.
argv :
Un tableau de chaînes de caractères qui représente la liste des arguments à passer au programme à exécuter.
argv[0] :
Contient le nom ou le chemin de la commande. C'est généralement interprété comme le nom du programme par les conventions Unix.
argv[1] :
Définie à NULL pour indiquer la fin de la liste des arguments.
Exemple pour une commande comme ls :
argv[0] = "ls"
argv[1] = NULL


Exécution de la commande
if (execve(argv[0], argv, NULL) == -1)

execve(argv[0], argv, NULL) :

Remplace le processus courant par le programme spécifié dans argv[0].
Arguments :
argv[0] : Chemin de l'exécutable ou nom de la commande.
argv : Tableau des arguments à passer au programme.
NULL : Environnement (ici, aucun environnement supplémentaire n'est fourni).
Si execve réussit, le processus courant est remplacé et l'exécution ne revient jamais dans cette fonction.
Si execve échoue, elle retourne -1.

gestion des erreur :
Si command = "ls" et le programme n'est pas trouvé, le message sera :
yaml
Copier le code
ls: No such file or director

Résumé de execute.c:
La fonction execute_command exécute une commande en remplaçant le processus courant par le programme spécifié. Si l'exécution échoue :

Un message d'erreur est affiché.
Le processus se termine avec un code d'échec.
Cette fonction est essentielle dans un shell, car elle exécute les commandes saisies par l'utilisateur. Elle suppose que le processus appelant a déjà été isolé (généralement via fork), car l'échec de execve entraîne la terminaison du processus.
////////////////////

Voici une explication détaillée de ce code :

Code Explication :
Ligne 1:
c
Copier le code
#include "shell.h"
Inclut le fichier d'en-tête shell.h, qui contient probablement les déclarations nécessaires pour les fonctions ou macros utilisées (comme printf).
Commentaire de la fonction :
c
Copier le code
/**
 * print_args - Affiche les arguments passés en ligne de commande
 * @av: Tableau des arguments
 */
Nom : print_args
Rôle :
Parcourir un tableau de chaînes de caractères (les arguments de la ligne de commande) et afficher chaque argument.
Paramètre :
av : Un tableau de chaînes de caractères représentant les arguments de la ligne de commande.
Habituellement, ce paramètre correspond au deuxième argument de la fonction main, soit char **argv.
Définition de la fonction :
c
Copier le code
void print_args(char **av)
Parcourir le tableau av pour afficher chaque argument.

int i = 0;
Une variable entière i est initialisée à 0. Elle sert d’index pour parcourir le tableau av.
while (av[i])
{
    printf("Argument %d: %s\n", i, av[i]);
    i++;
}
Condition de la boucle :
Tant que av[i] n'est pas NULL (la fin du tableau est marquée par un pointeur NULL), la boucle continue.
Corps de la boucle :
printf("Argument %d: %s\n", i, av[i]); :
Affiche l'index de l'argument (i) et son contenu (av[i]).
Exemple : Si av = {"./program", "arg1", "arg2", NULL} :
yaml
Copier le code
Argument 0: ./program
Argument 1: arg1
Argument 2: arg2
i++ :
Incrémente l'index pour passer à l'argument suivant
Résumé de args.c:
La fonction print_args est un utilitaire pour afficher les arguments d’un programme. Elle :

Parcourt un tableau d’arguments (souvent argv).
Affiche chaque argument avec son index.
Cette fonction peut être utilisée pour déboguer ou vérifier quels arguments ont été passés au programme lors de son exécution. Si appelée dans le contexte de main(int argc, char **argv), elle permet de visualiser tous les arguments fournis par l’utilisateur.
/////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
Inclut les bibliothèques nécessaires :
stdio.h : Pour les entrées/sorties (printf, etc.).
stdlib.h : Pour la gestion de la mémoire et l’arrêt du programme (malloc, exit, etc.).
unistd.h : Pour les fonctions système (fork, execve, etc.).
string.h : Pour la manipulation de chaînes (strcspn, etc.).
sys/types.h, sys/wait.h : Pour gérer les processus et leurs statuts (pid_t, waitpid, etc.).
errno.h : Pour gérer les erreurs système

Déclarations des fonctions :
c
Copier le code
void print_prompt(void);
char *read_command(void);
void execute_command(char *command);
void fork_wait_exec(char *command);
Liste les prototypes des fonctions définies dans le shell :
print_prompt : Affiche une invite de commande.
read_command : Lit une commande de l'utilisateur.
execute_command : Exécute une commande donnée.
fork_wait_exec : Crée un processus enfant, exécute la commande et attend sa fin.

Résumé de shell.h:
Ce fichier d'en-tête contient :

Les inclusions des bibliothèques nécessaires.
Les prototypes des fonctions principales du shell.
Une protection contre les inclusions multiples.
Il centralise les dépendances pour les fichiers utilisant ces fonctions et constantes.
