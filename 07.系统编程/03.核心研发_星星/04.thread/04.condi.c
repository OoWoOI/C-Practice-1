/*************************************************************************
	> File Name: 04.condi.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 03:03:28 PM CST
 ************************************************************************/

#include "./common/head.h"

typedef struct Goods{
    int data;
    struct Goods *next;
}Goods;


Goods *head = NULL;
pthread_mutex_t head_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t haveGoods = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    Goods *ng;
    while (1) {
        ng = (Goods *)malloc(sizeof(Goods));
        ng->data = rand() % 100;
        pthread_mutex_lock(&head_lock);
        
        //头插法
        ng->next = head;
        head = ng;
        
        pthread_mutex_unlock(&head_lock);
        pthread_cond_signal(&haveGoods);

        printf("producer : %d\n", ng->data);
        sleep(rand() % 3);
    }

   // return NULL;
}
void *consumer(void *arg) {
    Goods *k;
    while (1) {

        pthread_mutex_lock(&head_lock);
        
        if (!head) {
            pthread_cond_wait(&haveGoods, &head_lock);
        }
        
        k = head;
        head = head->next;
        pthread_mutex_unlock(&head_lock);
        
        printf("consumer : %d\n", k->data);
        free(k);
        sleep(rand() % 3);
    }
    //return NULL;
}


int main() {
    srand(time(0));
    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
