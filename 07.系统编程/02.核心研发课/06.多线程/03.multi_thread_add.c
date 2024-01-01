/*************************************************************************
	> File Name: 03.multi_thread_add.c
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jan 2024 03:33:25 PM CST
 ************************************************************************/

#include "head.h"
#define INS 5
#define MAX 100
int now;
int sum;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *work(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now > MAX) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        sum += now;
        usleep(15);
        now++;
        pthread_mutex_unlock(&mutex);
   // printf("now = %d sum = %d\n", now - 1, sum);
    }
}

int main() {
    pthread_t thread;
    for (int i = 0; i < INS; i++) {
        pthread_create(&thread, NULL, work, NULL);
    }
    usleep(15000);
    printf("now = %d sum = %d\n", now, sum);
    return 0;
}
