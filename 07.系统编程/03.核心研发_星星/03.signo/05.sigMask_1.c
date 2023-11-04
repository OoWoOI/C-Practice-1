/*************************************************************************
	> File Name: 05.sigMask_1.c
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Nov 2023 03:10:26 PM CST
 ************************************************************************/

#include "./common/head.h"

void print_MASK(const sigset_t *set) {
    
    for (int i = 1; i < 32; i++) {
        !sigismember(set, i) ? putchar('0') : putchar('1');
    }
    putchar(10);

    return ;
}


int main() {
    sigset_t set, old_set, pset;
    
   sigemptyset(&set);//初始化信号集
    //添加信号SIGINT、SIQQUIT
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    
    //设置阻塞信号
    sigprocmask(SIG_BLOCK, &set, &old_set);

    int n = 30;

    while (n--) {
        sigpending(&pset);
        print_MASK(&pset);
        sleep(1);
    }
    
    sigprocmask(SIG_SETMASK, &old_set, NULL);

    return 0;
}

