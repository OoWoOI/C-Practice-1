/*************************************************************************
	> File Name: 03.stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:28:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//栈结构
typedef struct Stack {
    int *data;
    int top;
    int size;
}Stack;

//初始化、插入、删除、输出、销毁、扩容

Stack *init(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

//判空
int is_empty(Stack *s) {
    return s->top == -1;
}
//获取栈顶元素
int top(Stack *s) {
    if (is_empty(s)) return -1;
    return s->data[s->top];
}

int exp(Stack *s) {
    int exp_szie = s->size;
    int *p = NULL;
    while (exp_szie) {
        p = (int *)realloc(s->data , sizeof(int) * (s->size + exp_szie));
        if (p) break;
        exp_szie /= 2;
    }

    if (p == NULL) return 0;
    free(s->data);
    s->data = p;
    s->size += exp_szie;
    return 1;
}

//插入
int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) {
        //扩容
        if (!exp(s)) {
            printf("expand is fail !\n");
            return 0;
        }
        printf("expand is successfually !\n");
    }
    s->data[++s->top] = val;
    return 1;
}

//删除
int pop(Stack *s) {
    if (s == NULL || is_empty(s)) return 0;
    s->top -= 1;
    return 1;
}

//遍历
void output(Stack *s) {
    if (s == NULL) return ;
    printf("[");
    for (int i = 0; i <= s->top; i++) {
       i && printf(" | ");
        printf("%d", s->data[i]);
    }
    printf("] ==> %d\n", s->top + 1);
    return ;
}


// 销毁
void clear(Stack *s) {
    if (s == NULL) return ;
    if (s->data) free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0)); 
    #define max_op 20
    Stack *s = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                int ret = push(s, val);
                printf("push val %d to stack is %s !\n", val, ret ? "successfually" : "fail");
                break;
            }
            case 3: {
                int ret = pop(s);
                printf("pop ele from to Stack is %s !\n", ret ? "successfually" : "fail");
                break;
            }
        }
        output(s);
    }
    clear(s);
    #undef max_op
    return 0;
}
