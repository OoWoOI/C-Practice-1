/*************************************************************************
	> File Name: 08.mySleep-1.c
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Nov 2023 02:55:35 PM CST
 ************************************************************************/

#include "./common/head.h"

void sig_alarm(int sec) {
    return ;
}


unsigned int mysleep(unsigned int sec) {
    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, susmask;

    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);//将newact的sa_mask重置为空
    
    sigaction(SIGALRM, &newact, &oldact);//设置新的信号捕捉行为
    
    //阻塞闹钟信号
    sigemptyset(&newmask);//重置信号屏蔽字
    sigaddset(&newmask, SIGALRM);//向信号集添加新的信号字
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);//更改新的信号阻塞

    //开启闹钟
    alarm(sec);

    //读取老的信号屏蔽字
    susmask = oldmask;
    //删除里面的alarm信号
    sigdelset(&susmask, SIGALRM);
    //临时设置信号屏蔽字为susmask，并挂起程序等待信号到来
    sigsuspend(&susmask);

    int unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    return unslept;
}


int main() {
   int n = 10;
    while (n--) {
        printf("mysleep 1 sec !\n");
        mysleep(1);
    }
    
    return 0;
}

