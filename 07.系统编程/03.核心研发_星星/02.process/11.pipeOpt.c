/*************************************************************************
	> File Name: 11.pipeOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 06:35:05 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    pid_t pid;
    int fd[2], n;
    char buff[20];
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork())  < 0) {
        perror("fork");
        exit(1);
    }
    


    if (pid) {
        close(fd[0]);//关闭读功能    
        write(fd[1], "hello my son!\n", 14);
        wait(NULL);
    } else {
        close(fd[1]);//关闭写功能
        sleep(3);
        n = read(fd[0], buff, 14);
        write(1, buff, n);
    }


    return 0;
}

