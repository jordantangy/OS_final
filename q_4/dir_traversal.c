#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int func(const char *file, const struct stat *sb, int flag, struct FTW *buff){
    
    if ( flag == FTW_SL || flag == FTW_SLN ) return 0;

     printf("%s %ld %s\n",  (flag == FTW_D) ? "D" : (flag == FTW_DNR) ? "DNR" :(flag == FTW_DP) ? "DP" : (flag == FTW_F) ? "F" : "???",
      (ino_t) sb->st_ino, file + buff->base);
    
    return 0;           
}

int main(int argc, char *argv[]) {
    /*
    Using ntfw function in order to recurse on the file tree.
    1- First argument is the filename entered in terminal
    2- Second argument is a ptr to stat buff that has infos about the file.
    3- Third argument : Number of max fd that ntfw function should use to recurse on the tree file.
    4- Fourth arguments FTW_PYS in order to tell the ntfw no to look up at soft links.
    */

    int val = nftw(argv[1],func, 10, FTW_PHYS); 
    exit(1);
}