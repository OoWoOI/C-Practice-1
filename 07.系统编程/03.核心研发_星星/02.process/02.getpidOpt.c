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
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {  
        n = 6;
        while (n--) {
            printf("child self %d parent %d!\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        n = 3;
        while (n--) {
            printf("father slef %d parent %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    return 0;
}

