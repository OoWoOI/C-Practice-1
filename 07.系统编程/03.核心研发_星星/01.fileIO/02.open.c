/*************************************************************************
	> File Name: 02.open.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Oct 2023 04:12:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char **argv) {
    
    if (argc < 2) {
        printf("usage: cmd filename !\n");
        exit(-1);
    }
    
    printf("%p\n", argv[1]);

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0777);
    //int fd = open(argv[1], O_WRONLY | O_CREAT,  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
   // int fd = open(argv[1], O_WRONLY);
  
    printf("%d\n", errno);
    
    if (fd < 0) {
        perror("OPEN");
        exit(-1);
    } else {
        printf("open file success!\n");
    }

    close(fd);
    
    return 0;
} 
