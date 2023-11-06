/*************************************************************************
	> File Name: 02.exitThread.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 03:30:48 PM CST
 ************************************************************************/

#include "./common/head.h"

void *phr_fn1(void *arg) {
    printf("thread 1 returning\n");
    return (void *)1;
}

void *phr_fn2(void *arg) {
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
    return NULL;
}

void *phr_fn3(void *arg) {
    while (1) {
        printf("thread 3 sleeping\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    void *sts;
    
    pthread_create(&tid, NULL, phr_fn1, NULL);
    pthread_join(tid, &sts);
    printf("thread 1 exit code %ld \n", (long)sts);

    pthread_create(&tid, NULL, phr_fn2, NULL);
    pthread_join(tid, &sts);
    printf("thread 2 exit code %ld \n", (long)sts);

    pthread_create(&tid, NULL, phr_fn3, NULL);
    sleep(3);

    pthread_cancel(tid);
    pthread_join(tid, &sts);
    printf("thread 3 exit code %ld \n", (long)sts);
    
    

    return 0;
}

