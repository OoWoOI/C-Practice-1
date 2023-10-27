/*************************************************************************
	> File Name: 18.dupOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Oct 2023 04:35:47 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    int fd, save_fd;

    if ( (fd = open("./test.txt", O_RDWR)) < 0) {
        perror("open");
        exit(1);
    }
    save_fd = dup(1);//将标准输入的文件描述符复制到save_fd
    dup2(fd, 1);//将fd指向的文件复制给标准输出
    write(1, "123", 3);
    close(fd);
    dup2(save_fd, 1);
    write(1, "123", 3);
    close(save_fd);
    return 0;
}

