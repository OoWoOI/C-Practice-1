/*************************************************************************
	> File Name: 04.sigMask.c
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Nov 2023 02:51:24 PM CST
 ************************************************************************/

#include "./common/head.h"
int main() {
   sigset_t set, oldset;//信号集
    sigemptyset(&set);//初始化信号集
    sigaddset(&set, SIGINT);//设置信号

    sigprocmask(SIG_BLOCK, &set, &oldset);//修改信号
    
    int n = 10;
    while (n--) {
        printf("sleep 1 sec!\n");
        sleep(1);
    }

    sigprocmask(SIG_SETMASK, &oldset, NULL);

    n = 10;
    
    while (n--) {
        printf("sleep 1 sec!\n");
        sleep(1);
    }

    return 0;
}
