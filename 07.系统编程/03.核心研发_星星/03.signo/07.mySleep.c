/*************************************************************************
	> File Name: 07.mySleep.c
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Nov 2023 02:18:39 PM CST
 ************************************************************************/

#include "./common/head.h"

void sig_alarm(int signo) {

    return ;
}

unsigned int mysleep(unsigned int sec) {
    struct sigaction newact, oldact;
    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);
    
    sigaction(SIGALRM, &newact, &oldact);
    
    alarm(sec);
    pause();

    int unslept = alarm(0);



    sigaction(SIGALRM, &oldact, NULL);

    return unslept;
}


int main() {
    int n = 20;
    
    while (n--) {
        printf("sleep 1 sec!\n");
        mysleep(1);
    }
    
    return 0;
}

