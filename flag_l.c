#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#include "functions.h"

// Fonction pour afficher les détails d'un fichier "-l"
void my_l(const char *path) 
{
    struct stat file_stat;

    if (stat(path, &file_stat) == 0) 
    {
        //Si un Directory
        printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");

        // Permissions
        printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");

        //Permission Groupe
        printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");

        //Permission Other
        printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
        printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");

        // Number of links
        printf("%ld ", (long)file_stat.st_nlink);

        // Owner
        struct passwd *pw = getpwuid(file_stat.st_uid);
        printf("%s ", pw ? pw->pw_name : "unknown");

        // Group
        struct group *gr = getgrgid(file_stat.st_gid);
        printf("%s ", gr ? gr->gr_name : "unknown");

        // File size
        printf("%lld ", (long long)file_stat.st_size);

        // Last modification time
        struct tm *tm_info = localtime(&file_stat.st_mtime);
        char mod_time[20];
        strftime(mod_time, sizeof(mod_time), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s ", mod_time);

        // File name
        if ((S_ISDIR(file_stat.st_mode))) 
        {
            print_highlighted_green(path);
            printf("\n");
        }
        else {printf("%s\n", path);
        }
    } 
    else 
    {
        perror("Erreur lors de la récupération des informations sur le fichier");
    }
}



// Fonction pour afficher le total des blocs utilisés par tous les fichiers dans un répertoire
void print_total_blocks(const char *path) 
{
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir;

    long long total_blocks = 0;

    dir = opendir(path);
    if (dir == NULL) 
    {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if(entry->d_name[0] != '.')
        {
            char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == 0) 
        {
            total_blocks += file_stat.st_blocks;
        } 
        else 
        {
            perror("Erreur lors de la récupération des informations sur le fichier");
        }
        }
    }

    closedir(dir);

    printf("Total %lld\n", total_blocks);
}
