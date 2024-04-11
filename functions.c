#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#include "functions.h"

void list_directory(const char *path, struct Flags flags) {
    DIR *dir;
    struct dirent *entry;
    char **file_names = NULL; // tableau de noms de fichiers
    int num_files = 0;

    if ((dir = opendir(path)) != NULL) {
        if (flags.d) {
            printf("%s\n", path);
            closedir(dir);
            return;
        }
        if(flags.l ) {
            print_total_blocks(path);
        }
        while ((entry = readdir(dir)) != NULL) {
            if (!flags.a && entry->d_name[0] == '.') {
                continue;
            } else if (flags.A && (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)) {
                continue;
            } else if (flags.L) {
                my_L(path, entry, flags);
            } else if (flags.l) {
                my_l(entry->d_name);
            } else if (flags.r || flags.t) {
                file_names = (char **)realloc(file_names, (num_files + 1) * sizeof(char *));
                if (file_names == NULL) {
                    perror("Allocation mémoire échouée");
                    exit(EXIT_FAILURE);
                }
                file_names[num_files] = strdup(entry->d_name);
                if (file_names[num_files] == NULL) {
                    perror("Allocation mémoire échouée");
                    exit(EXIT_FAILURE);
                }
                num_files++;
            } else if (flags.flage1) {
                printf("%s\n", entry->d_name);
            } else {
                if (entry->d_type == DT_DIR || entry->d_name[0] == '.') { // Vérifie si c'est un répertoire
                    print_highlighted_green(entry->d_name); // Imprime en surbrillance verte si c'est un répertoire
                } else {
                    printf("%s", entry->d_name);
                }
            }
            printf("  "); // Ajoute un espace entre les noms de fichier
        }
        printf("\n");
        if (flags.r) {
            my_r(file_names, num_files);
        } else if (flags.t) {
            my_t(file_names, num_files);
        } else if (flags.R) {
            if (!flags.d) {
                my_R(path, &flags);
            }
        }
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
    }
}
