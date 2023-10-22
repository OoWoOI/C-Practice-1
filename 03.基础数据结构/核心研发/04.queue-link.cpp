/*************************************************************************
	> File Name: 04.queue-link.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Oct 2023 09:45:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//队列链表实现: 初始化、插入、删除、遍历、获取队首元素、判空操作、销毁
typedef struct Node {
    int val;
    struct Node *next;
}Node;

typedef struct queue {
    Node *head, *tail;
    int cnt;
} queue;

//获取队首元素
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;
    return p;
}

//初始化队列
queue *init() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = q->tail = NULL;
    q->cnt = 0;
    return q;
}

//判空操作
int is_empty(queue *q) {
    return q->head == NULL;
}

//获取栈顶元素
int top(queue *q) {
    return q->head->val;
}

//插入元素
int push(queue *q, int val) {
    if (q == NULL) return 0;
    if (q->head == NULL) {
        q->head = getNewNode(val);
        q->tail = q->head;
    } else {
        q->tail->next = getNewNode(val);
        q->tail = q->tail->next;
    }
    q->cnt += 1;
    return 1;
}

//删除元素
int pop(queue *q) {
    if (q == NULL || is_empty(q)) return 0; 
    Node *p = q->head;
    q->head = p->next;
    free(p);
    q->cnt -= 1;
    return 1;
}

//遍历
void output(queue *q) {
    printf("[");
    int flag = 0;
    for (Node *p = q->head; p; p = p->next) {
        flag && printf(" <== ");
        printf("%d", p->val);
        flag = 1;
    }
    printf("] ==> %d\n", q->cnt);
    return ;
}

//销毁队列
void clear(queue *que) {
    if (que == NULL) return ;
    Node *p = que->head, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(que);
    return ;
}

int main() {
    srand(time(0)); 
    #define max_op 20
    queue *q = init();
    for (int i = 0; i < max_op; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
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
