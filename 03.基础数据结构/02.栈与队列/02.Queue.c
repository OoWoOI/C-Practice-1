/*************************************************************************
	> File Name: 02.Queue.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Aug 2023 08:03:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
*
*循环队列：
*   （1）初始化
*   （2）判空
*   （3）获取队首元素
*   （4）入队
*   （5）出队
*   （6）遍历
*   （7）销毁
* */

typedef struct Queue {
    int *data;
    int head, tail, size, cnt;
} Queue;

//获取新队列
Queue* getQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * (size + 5));
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

//判空操作
int empty(Queue *q) {
    return q->cnt == 0;
}

//获取队首元素
int front(Queue *q) {
    if (empty(q)) return -1;
    return q->data[q->head];
}

//入队
int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[q->tail++] = val;
    if (q->tail >= q->size) q->tail -= q->size;
    q->cnt++;
    return 1;
}

//出队
int pop(Queue *q ){
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head >= q->size) q->head -= q->size;
    q->cnt--;
    return 1;
}

//销毁队列
void destroy(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

//遍历队列
void output(Queue *q) {
    if (q == NULL) return ;
    printf("[");
    for (int i = 0 ; i < q->cnt; i++) {
        i && printf(", ");
        printf("%d", q->data[(q->head + i) % q->size]);
    }
    printf("]===>Queue(%d)\n", q->cnt);
    return ;
}


int main() {
    srand(time(0));
    #define max_op 10
    int op, val;
    Queue *q = getQueue(5);
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int top = front(q);
                printf("Push val(%d) to the Queue(%d) is %s\n", val, top, push(q, val) ? "YES" : "NO");
            } break;
            case 3: {
                int top = front(q);
                printf("Pop the val(%d) from the Queue is %s!\n", top, pop(q) ? "YES" : "NO");
                
            } break;
        }
        output(q);
    }
    destroy(q);
    #undef max_op
    return 0;
}
