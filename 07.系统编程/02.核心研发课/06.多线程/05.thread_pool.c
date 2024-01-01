/*************************************************************************
	> File Name: 05.thread_pool.c
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jan 2024 07:42:33 PM CST
 ************************************************************************/

#include "head.h"

void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    taskQueue->data = calloc(size, sizeof(void *));
    return ;
}

void task_queue_push(struct task_queue *taskQueue, char *str) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        printf("taskQueue is full!\n");
        pthread_mutex_unlock(&taskQueue->mutex);
        return ;
    }
    printf("<Push> : %s\n", str);
    taskQueue->data[taskQueue->tail] = str;
    taskQueue->tail++;
    taskQueue->total++;
    if (taskQueue->tail == taskQueue->size) {
        printf("taskQueue reached end!\n");
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
}

char *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == 0) {
        printf("taskQueue is empty!\n");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    char *str = taskQueue->data[taskQueue->head];
    printf("<Pop> : %s\n", str);
    taskQueue->total--;
    taskQueue->head++;
    if (taskQueue->head == taskQueue->size) {
        printf("taskQueue head reached end!\n");
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return str;
}
