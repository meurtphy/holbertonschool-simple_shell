#include <stdio.h>

int main(int ac, char **av) {
    printf("Nombre d'arguments : %d\n", ac);

    for (int i = 0; i < ac; i++) {
        printf("Argument %d : %s\n", i, av[i]);
    }

    return 0;
}
