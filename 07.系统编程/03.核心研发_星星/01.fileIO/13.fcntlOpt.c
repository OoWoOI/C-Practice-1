/*************************************************************************
	> File Name: 13.fcntlOpt.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Oct 2023 02:50:51 PM CST
 ************************************************************************/

#include "./common/head.h"
int main(int argc, char *argv[]){
    
    if (argc < 2) {
        fprintf(stderr, "usage: cmd + filename\n");
        exit(1);
    }
    
    int flags;
    
    if ((flags = fcntl(atoi(argv[1]), F_GETFL)) < 0) {
        perror("fcntl get flags");
        exit(1);
    }
   
    //判断文件的权限
    
    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("read only\n");
            break;
        case O_WRONLY:
            printf("write  only\n");
            break;
        case O_RDWR:
            printf("read write\n");
            break;
        default:
            printf("invalid access mode\n");
            break;
    }

    printf("flags = %#x\n", flags);
    
    return 0;
}
