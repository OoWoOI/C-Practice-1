/*************************************************************************
	> File Name: 05.sem.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 03:49:35 PM CST
 ************************************************************************/

#include"./common/head.h"

#define NUM 5


int q[NUM];
sem_t blank_number, goods_number;

void *producer(void *arg) {
    int i = 0;
    while (1) {
        sem_wait(&blank_number);

        q[i] = rand() % 100 + 1;
        printf("producer : %d\n", q[i]);

        sem_post(&goods_number);
        i = (i + 1) % NUM;
        sleep(rand() % 3);
    }

}

void *consumer(void *arg) {
    int i = 0;
    while (1) {
        sem_wait(&goods_number);
        printf("consumer : %d\n", q[i]);
        q[i] = 0;
        sem_post(&blank_number);
        i = (i + 1) % NUM;
        sleep(rand() % 3);
    }
}

int main() {
    srand(time(0));
    
    sem_init(&blank_number, 0, NUM);
    sem_init(&goods_number, 0, NUM);

    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&pid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}

