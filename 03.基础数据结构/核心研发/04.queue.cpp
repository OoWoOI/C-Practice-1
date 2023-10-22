/*************************************************************************
	> File Name: 04.queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:28:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct queue{
    int *data;
    int head, tail;
    int size, cnt;
} queue;

//初始化队列
queue *init(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->size = size;
    q->cnt = 0;
    return q;
}

//判空
int is_empty(queue *q) {
    return q->cnt == 0;
}

//获取队首元素
int front(queue *q) {
    return q->data[q->head];
}

//扩容
int exp(queue *q) {
    int exp_size = q->size;
    int *p = (int *)malloc(sizeof(int) * (q->size + exp_size));
    for (int i = 0; i < q->size; i++) {
        p[i] = (q->head + i) % q->size;
    }
    q->size += exp_size;
    return 1;
}

//入队
int push(queue *q, int val) {
    if (q == NULL) return 0;
    if (q->tail + 1 == q->head) {
        if (!exp(q)) {
            printf("expand fail !\n");
            return 0;
        }
        printf("expand success !\n");
    }
    if (q->tail == q->size) {
        q->tail -= q->size;
    }
    q->data[q->tail++] = val;
    q->cnt += 1;
    return 1;
}

//出队
int pop(queue *q) {
    if (q == NULL || is_empty(q)) return 0;
    q->head = (q->head + 1) % q->size;
    q->cnt -= 1;
    return 1;
}

//遍历
void output(queue *q) {
    if (q == NULL) return ;
    printf("[");
    for (int i = 0; i < q->cnt; i++) {
        i && printf("<==");
        printf("%d", q->data[(i + q->head) % q->size]);
    }
    printf("] ==> %d\n", q->cnt);
    return ;
}

//销毁队列结构
void clear(queue *q) {
    if (q == NULL) return ;
    if (q->data) free(q->data);
    free(q);
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int op = rand() % 4;
        int val = rand () % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int ret = push(q, val);
                printf("push val %d to queue is %s!\n", val, ret ? "success" : "fail");
                break;
            }
            case 3: {
                int ret = pop(q);
                printf("pop ele from queue is %s!\n", ret ? "success" : "fail");
                break;
            }
        }
        output(q);
    }
    clear(q);
    #undef max_op
    return 0;
}
