/*************************************************************************
	> File Name: 01.forkOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 03:20:09 PM CST
 ************************************************************************/

#include "./common/head.h"

int main(){
    char *msg;
    int n;
    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }

        if (!pid) {
            printf("child[%d] self %d parent %d\n", i, getpid(), getppid());
            sleep(1);
            break;
        }
    }
    return 0;
}

