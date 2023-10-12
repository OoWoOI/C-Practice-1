/*************************************************************************
	> File Name: 02.生成100个子进程.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Oct 2023 02:45:27 PM CST
 ************************************************************************/

#include"./common/head.h"
int main() {
    pid_t pid;
    int i;
    for (i = 1; i <= 100; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) break;
    }
    if (pid == 0) {
        sleep(1);
        printf("I'm %dth child !\n", i);
    } else {
        for (i = 1; i <= 100; i++) wait(NULL);
        printf("I'm parent !\n");
    }

    return 0;
}
