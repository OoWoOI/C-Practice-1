/*************************************************************************
	> File Name: 04.cp_fd.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 04:22:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int rfd, wfd;
   
    if ( (rfd = open(argv[1], O_RDONLY, 0666)) < 0 ) {
        perror("open rfd");
        exit(1);
    } 

    if ( (wfd = open(argv[2], O_CREAT | O_RDWR, 0666)) < 0) {
        perror("open wfd");
        exit(1);
    }

    //两个文件描述符都成功打开后就可以实现文件的读写操作。

    while (1) {
        char buf[512] = {0};
        int cnt = read(rfd, buf, 512);
        
        if (cnt <= 0) {
            break;
        }
    
        write(wfd, buf, cnt);

    }
    close(rfd);
    close(wfd);
    return 0;
}
