/*************************************************************************
	> File Name: 06.handle.c
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Nov 2023 04:00:11 PM CST
 ************************************************************************/

#include "./common/head.h"


void undead(int signo) {
    printf("get signo=%d , I'm happy, I'm alive!\n", signo);
    return ;
}

int main() {
    struct sigaction newact, oldact;
    newact.sa_handler = undead;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);
    
    sigaction(SIGINT, &newact, &oldact);
    
    int n = 20;

    while (n--) {
        sleep(1);
    }

    sigaction(SIGINT, &oldact, NULL);

    return 0;
}
