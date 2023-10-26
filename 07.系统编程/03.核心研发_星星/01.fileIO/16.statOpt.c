/*************************************************************************
	> File Name: 16.statOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 04:10:08 PM CST
 ************************************************************************/

#include "./common/head.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage : cmd + filename | dirname\n");
        exit(1);
    } 
    
    struct stat st;
    stat(argv[1], &st);
    
    /* 
    if (S_ISDIR(st.st_mode)) {
        printf("dir\n");
    } else 
        printf("other\n");
    */
    
    /*
    *   case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
    * */

    switch(st.st_mode & S_IFMT) {
          case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;

    }


    return 0;
}

