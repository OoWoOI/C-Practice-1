/*************************************************************************
	> File Name: 02.fork_创建10个子进程.c
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 02:56:24 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid = 0;
    int i = 0;
    for (; i < 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) break;
    }
    if (pid == 0)
    printf("I'm this %dth child<pid = %d>!\n", i + 1, getpid());
    else {
        sleep(1);    
    }
    return 0;
}

