/*************************************************************************
	> File Name: 01.pthread_create.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 02:33:24 PM CST
 ************************************************************************/

#include "./common/head.h"

void *thr_fn(void *);

void printid(char *tip) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid : %d tid : %ld (%p)\n", tip, pid, tid, &tid);
    printf("%s thr_fn = %p\n", tip, thr_fn);
    return ;
}

void *thr_fn(void *arg) {
    printid(arg);
    return NULL;
}

int main() {
    pthread_t ntid;
    int ret = pthread_create(&ntid, NULL, thr_fn, "new thread");
    if (ret) {
        printf("create thread err : %s\n", strerror(ret));
        exit(1);
    }
    sleep(1); 
    printid("maint thread");

    return 0;
}
