/*************************************************************************
	> File Name: 03.read.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 02:27:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv) {
    
    if (argc < 2) {
        perror("argment too few!");
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    
    if (fd < 0) {
        perror("OPEN");
        exit(1);
    }

    //打开文件成功
    char buff[1024];
    ssize_t n;
    n = read(fd, buff, 10);
    
    for (int i = 0; i < n; i++) 
        printf("%c", buff[i]);

    printf("\n");
    n = read(fd, buff, 10);

    for (int i = 0; i < n; i++) 
        printf("%c", buff[i]);
    printf("\n");
    
    close(fd);
    return 0;
}
