/*************************************************************************
	> File Name: 03.addnum.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 03:56:35 PM CST
 ************************************************************************/

#include "./common/head.h"

pthread_mutex_t add_lock = PTHREAD_MUTEX_INITIALIZER;


int cnt = 0;

void *cntadd(void *arg) {
    int val;
    for (int i = 0; i < 5000; i++) {
        pthread_mutex_lock(&add_lock);
        val = cnt;
        printf("%p : %d\n", (void *)pthread_self(), val);
        cnt = val + 1;
        pthread_mutex_unlock(&add_lock);
    }

    return NULL;
}

int main() {
    pthread_t tida, tidb;

    pthread_create(&tida, NULL, cntadd, NULL);
    pthread_create(&tidb, NULL, cntadd, NULL);

    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);
    return 0;
}
