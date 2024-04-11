#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

#include "functions.h"

void my_R(const char *path, struct Flags *flags)
{
    DIR *subdir;
    struct dirent *entry; // Declare entry variable
    subdir = opendir(path); // Correct variable name
    printf("\n");
    while ((entry = readdir(subdir)) != NULL) { // Correct variable name
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && entry->d_name[0] != '.') 
        {
            char subdir_path[PATH_MAX];
            snprintf(subdir_path, PATH_MAX, "%s/%s", path, entry->d_name);
            DIR *subdir = opendir(subdir_path); // Correct variable declaration
            printf("%s\n",subdir_path);
            if (subdir != NULL) 
            {
                list_directory(subdir_path, *flags); // Pass flags directly
                closedir(subdir);
            }
            else 
            {
                perror("Erreur lors de l'ouverture du sous-répertoire");
            }
        }
    }
    closedir(subdir);
}