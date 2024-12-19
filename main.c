#include <stdio.h>
#include <stdlib.h>
#include "split_string.h" // Ajoutez un fichier d'en-tête pour la fonction split_string

int main(void)
{
    char input[] = "This is a test string";
    char **words;
    int i;

    words = split_string(input);  // Appel de la fonction
    if (words == NULL)
    {
        printf("No words found.\n");
        return (1);
    }

    printf("Words in the string:\n");
    for (i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
    }

    free(words);
    return (0);
}
