#include <stdio.h>      // Pour fprintf(), stderr
#include <stdlib.h>     // Pour exit()
#include <unistd.h>     // Pour getopt()

#include "functions.h"



struct Flags process_flags(int argc, char *argv[]) 
{
    struct Flags flags = {false, false, false, false, false, false, false, false, false};
    int opt;
    
    while ((opt = getopt(argc, argv, "1lRrdtaAL")) != -1) 
    {
        switch (opt) 
        {
            case '1':
                flags.flage1 = true;
                break;
            case 'l':
                flags.l = true;
                break;
            case 'R':
                flags.R = true;
                break;
            case 'r':
                flags.r = true;
                break;
            case 'd':
                flags.d = true;
                break;
            case 't':
                flags.t = true;
                break;
            case 'a':
                flags.a = true;
                break;
            case 'A':
                flags.A = true;
                flags.a = true;
                break;
            case 'L':
                flags.L = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-1lRrdtaAL] [directory...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return flags;
}
