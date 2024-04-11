
#include <stdio.h>

#include "functions.h"

// Fonction pour imprimer le nom en surbrillance verte
void print_highlighted_green(const char *name) {
    printf("\033[1;32m%s\033[0m  ", name); // Code de couleur pour le vert en surbrillance
}
