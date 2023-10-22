/*************************************************************************
	> File Name: 03.stack-link.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Oct 2023 08:08:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
* 链表实现栈结构：初始化、插入、删除、遍历、销毁
*
* */

typedef struct Node {
    int val;
    struct Node *next;
}Node;

typedef struct Stack {
    Node *top;
}Stack;

//初始化、入栈、弹栈、遍历、销毁、判空、获取栈顶元素

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

//初始化栈结构
Stack *init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

//判空操作
int is_empty(Stack *s) {
    return s->top == NULL;
}

//获取栈顶元素
int top(Stack *s) {
    return s->top->val;
} 


//插入数据
int push(Stack *s, int val) {
    if (s == NULL) return 0;
    Node *p = s->top;
    s->top = getNewNode(val);
    s->top->next = p;
    return 1;
}

//出栈
int pop(Stack *s) {
    if (s == NULL || is_empty(s)) return 0;
    Node *p = s->top;
    s->top = p->next;
    free(p);
    return 1;
}

void output(Stack *s) {
    if (s == NULL) return ;
    int flag = 0;
    printf("[");
    for (Node *p = s->top; p; p = p->next) {
        flag && printf("<==");
        printf("%d", p->val);
        flag += 1;
    }
    printf("] ==> %d\n", flag);
    return ;
}

//销毁
void clear(Stack *s) {
    if (s == NULL) return ;
    Node *p = s->top, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(s);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = init();
    for (int i = 0; i < max_op; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int ret = push(s, val);
                printf("push val %d to stack is %s!\n", val, ret ? "successfually" : "fail");
                break;
            };
            case 3: {
                int ret = pop(s);
                printf("pop ele from stack is %s!\n", ret ? "successfually" : "fail");
                break;
            }
        }
        output(s);
    }
    clear(s);
    #undef max_op
    return 0;
}
