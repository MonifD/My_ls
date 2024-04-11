#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_COLOR_GREEN  "\x1b[32m"

#include "functions.h"

void my_L(const char *path, const struct dirent *entry, struct Flags flags) 
{
    // Déclarer une structure stat pour stocker les informations sur le fichier
    struct stat file_stat = {0};

    // Récupérer les informations sur le fichier
    if (lstat(entry->d_name, &file_stat) == -1) 
    {
        perror("Erreur lors de la lecture des informations sur le fichier");
        return;
    }

    // Si l'option -L est spécifiée et que le fichier est un lien symbolique
    if (flags.L && S_ISLNK(file_stat.st_mode)) 
    {
        // Récupérer le chemin complet du lien symbolique
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Récupérer le chemin cible du lien symbolique
        char target[PATH_MAX];
        ssize_t len = readlink(full_path, target, sizeof(target) - 1);
        if (len != -1) {
            target[len] = '\0';

            // Afficher le nom du fichier cible en bleu
            printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET "  ", target);
        } else {
            perror("Erreur lors de la lecture du lien symbolique");
        }
    } 
    else if (S_ISDIR(file_stat.st_mode)) 
    {
        // Si le fichier est un répertoire, imprimer son nom en surbrillance verte
        print_highlighted_green(entry->d_name);
        printf("  ");
    } 
    else 
    {
        // Si le fichier n'est pas un lien symbolique ou un répertoire, afficher son nom
        printf("%s  ", entry->d_name);
    }
}
