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
        msg = "child process~";  
        n = 6;
    } else {
        msg = "parent process~";
        n = 3;
    }
    while (n--) {
        printf("%s\n", msg);
        sleep(1);
    }
    return 0;
}

