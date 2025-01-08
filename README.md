Structure des fichiers et de leurs fonctions
1. main.c
Rôle : Point d'entrée du programme. Il gère la boucle principale qui lit et exécute les commandes utilisateur.
Fonctions utilisées :
print_prompt : Affiche l'invite de commande (par exemple $ ).
read_command : Lit la commande saisie par l'utilisateur.
fork_wait_exec : Crée un processus enfant pour exécuter la commande.
Lien avec les autres fichiers :
Appelle des fonctions déclarées dans shell.h et définies dans d'autres fichiers.
2. print_prompt.c
Rôle : Affiche l'invite de commande si le shell est en mode interactif.
Lien avec les autres fichiers :
Appelée par main.c pour afficher $ avant chaque commande.
3. read_command.c
Rôle : Lit la commande entrée par l'utilisateur via la ligne de commande.
Détails :
Utilise getline pour lire l'entrée utilisateur.
Supprime le caractère de nouvelle ligne (\n) à la fin de la commande.
Lien avec les autres fichiers :
Appelée par main.c pour obtenir l'entrée utilisateur.
4. fork_wait_exec.c
Rôle : Gère le processus d'exécution d'une commande.
Détails :
Utilise fork pour créer un processus enfant.
Appelle execute_command dans le processus enfant pour exécuter la commande.
Attend la fin de l'exécution du processus enfant dans le processus parent.
Lien avec les autres fichiers :
Appelle execute_command pour lancer la commande.
Appelée par main.c pour exécuter une commande.
5. execute_command.c
Rôle : Exécute une commande spécifique.
Détails :
Utilise execve pour remplacer le processus en cours par celui de la commande.
Gère les erreurs si la commande n'est pas trouvée.
Lien avec les autres fichiers :
Appelée par fork_wait_exec pour exécuter une commande.
6. print_args.c
Rôle : Affiche les arguments de la ligne de commande (utile pour le débogage ou les tests).
Lien avec les autres fichiers :
Peut être utilisée pour afficher les arguments passés à une commande.
7. print_pid.c
Rôle : Affiche l'ID du processus en cours (PID) et celui du processus parent (PPID).
Lien avec les autres fichiers :
Peut être utilisée dans des commandes spécifiques pour afficher des informations système.
8. handle_exit.c
Rôle : Vérifie si la commande saisie est exit et termine le programme si c'est le cas.
Lien avec les autres fichiers :
Peut être intégrée dans la boucle principale de main.c pour gérer la sortie du shell.
9. shell.h
Rôle : Fichier d'en-tête contenant toutes les déclarations des fonctions et des inclusions nécessaires.
Détails :
Inclut les bibliothèques standard (stdio.h, stdlib.h, etc.).
Déclare toutes les fonctions utilisées dans le projet.
Lien avec les autres fichiers :
Inclut dans tous les fichiers .c pour fournir les déclarations nécessaires.
Comment ces fichiers sont reliés
main.c est le point central :

Il utilise print_prompt pour afficher l'invite.
Il utilise read_command pour lire une commande utilisateur.
Il appelle fork_wait_exec pour exécuter la commande.
fork_wait_exec.c :

Utilise execute_command pour exécuter la commande dans un processus enfant.
execute_command.c :

Utilise execve pour lancer la commande et environ pour passer les variables d'environnement.
handle_exit.c :

Peut être appelée dans main.c pour gérer la commande exit.
print_args.c :

Utile pour déboguer ou afficher les arguments dans un processus.
print_pid.c :

Peut être utilisée pour afficher des informations système si nécessaire.
print_prompt.c et read_command.c :

Travaillent ensemble pour interagir avec l'utilisateur : afficher une invite et lire les entrées.
shell.h :


Exemple de flux :
Affichage de l'invite : main.c → print_prompt.
Lecture de la commande : main.c → read_command.
Exécution de la commande :
main.c → fork_wait_exec.
fork_wait_exec → execute_command.
Gestion des erreurs et sortie : main.c → handle_exit.