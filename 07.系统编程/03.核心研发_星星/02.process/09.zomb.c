/*************************************************************************
	> File Name: 09.zomb.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 05:06:38 PM CST
 ************************************************************************/

#include"./common/head.h"
int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid) {
        printf("I'm father process!\n");
        while (1) sleep(1);
    } else {
        printf("I'm child process!\n");
        exit(3);
    }

    return 0;
}
