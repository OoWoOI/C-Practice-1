/*************************************************************************
	> File Name: 03.copy_fd.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 03:47:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
   int fd;
   if ((fd = open(argv[1], O_RDONLY, 0666)) < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        char buf[512] = {0};
        int flag = read(fd, buf, 1);
        if (flag <= 0) {
            break;
        }
        printf("%s", buf);
    }
    
    return 0;
}
