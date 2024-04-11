#include <unistd.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    struct Flags flags = process_flags(argc, argv);
    
    // If no directory provided, list current directory
    if (optind == argc) {
        list_directory(".", flags);
    } else {
        // Loop through directories provided as arguments
        for (int i = optind; i < argc; ++i) {
            list_directory(argv[i], flags);
        }
    }

    return 0;
}
