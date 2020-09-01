#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//The stat() function shall obtain information about the named file and write it to the area pointed to by the buf argument.
//1st arg - fpath is the pathname of the entry
//2nd arg - is a pointer to the stat structure returned by a call to stat(2) for fpath.
/*3rd arg - an integer that has one of the following values:
  FTW_F fpath is a regular file.
  FTW_D fpath is a directory.
  FTW_DNR fpath is a directory which can't be read.
  FTW_SL fpath is a symbolic link, and FTW_PHYS was set in flags.
  FTW_DP fpath is a directory where all of the files and subdirectories within fpath have been processed.
  FTW_SLN fpath is a symbolic link pointing to a nonexistent file.
*/
/*4th arg -  The fourth argument (ftwbuf) that nftw() supplies when calling fn() is a pointer to a structure of type FTW:
           struct FTW {
               int base;
               int level;
           };

       base is the offset of the filename in the pathname given in fpath.
       level is the depth of fpath in the directory tree, relative to the root of the tree (dirpath, which has depth 0).
*/       

// hard link : ln <original file name> <new file name to link>
// soft link : ln -s <original file name> <new file name to link>
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