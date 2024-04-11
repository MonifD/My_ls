#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

struct Flags
{
    bool flage1; // 👌
    bool l;      // 👌
    bool R;      // 👌
    bool r;      // 👌
    bool d;      // 👌
    bool t;      // 👌
    bool a;      // 👌
    bool A;      // 👌
    bool L;      // 👌
};

struct dirent;
void list_directory(const char *path, struct Flags flags);
void print_highlighted_green(const char *name);
struct Flags process_flags(int argc, char *argv[]);
void my_l(const char *path);
void print_total_blocks(const char *path);
void my_r(char **arr, int size);
void my_t(char **arr, int size);
void my_R(const char *path, struct Flags *flags);
void my_L(const char *path, const struct dirent *entry, struct Flags flags);

#endif
