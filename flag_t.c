#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "functions.h"



void my_t(char **arr, int size)
{
    int i, j;
    char *temp;
    struct stat stat_a, stat_b;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            stat(arr[j], &stat_a);
            stat(arr[j + 1], &stat_b);

            if (stat_a.st_mtime < stat_b.st_mtime) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        struct stat file_stat;
        if (lstat(arr[i], &file_stat) == -1) 
        {
            perror("Erreur lors de l'appel à lstat");
            exit(EXIT_FAILURE);
        }
        if (S_ISDIR(file_stat.st_mode)) // Vérifie si c'est un répertoire
        { 
            print_highlighted_green(arr[i]); // Imprime en surbrillance verte si c'est un répertoire
        }
        else 
        {
            printf("%s  ", arr[i]);
        }
        free(arr[i]);
    }
    printf("\n");
    free(arr);
}