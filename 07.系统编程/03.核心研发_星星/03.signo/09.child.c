/*************************************************************************
	> File Name: 09.child.c
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Nov 2023 03:36:23 PM CST
 ************************************************************************/

#include "./common/head.h"

void sig_child(int signo) {
    int sts;
    wait(&sts);
    if (WIFEXITED(sts)) {
        printf("exit with code %d\n", WEXITSTATUS(sts));
    } else {
        printf("lemon %d\n", WEXITSTATUS(sts));
    }
    return ;
}


int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid) {
        struct sigaction newact, oldact;
        
        newact.sa_handler = sig_child;
        sigemptyset(&newact.sa_mask);
        newact.sa_flags = 0;
        sigaction(SIGCHLD, &newact, &oldact);
        
        int n = 10;
        while (n--) {
            printf("work~~\n");
            sleep(1);
        }
         
    } else {
        sleep(3);
        exit(2);
    }

    return 0;
}

