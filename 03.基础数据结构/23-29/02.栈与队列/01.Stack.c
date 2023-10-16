/*************************************************************************
	> File Name: 01.Stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Aug 2023 12:10:51 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Stack {
    int *data;
    int top, size;
}Stack;

//栈结构：结构定义、初始化、插入、删除、获取栈顶元素、判空操作、遍历

//初始化栈结构
Stack *getStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * (size + 5));
    s->size = size;
    s->top = -1;
    return s;
}

//判空操作
int empty(Stack *s) {
    if (s == NULL) return 1;
    return s->top == -1;
}


//获取栈顶元素
int top(Stack *s) {
    if (empty(s)) return -1;
    return s->data[s->top];
}

//入栈
int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 >= s->size) {
        printf("Stack is Full !\n");
        return 0;
    }
    s->data[++s->top] = val;
    return 1;
}

//弹栈
int pop(Stack *s) {
    if (s == NULL || empty(s)) return 0;
    s->top--;
    return 1;
}

//销毁
void clear(Stack *s) {
    if (s == NULL) return ;        
    free(s->data);
    free(s);
    return ;
}

//遍历
void output(Stack *s) {
    if (s == NULL) return ;
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        i && printf(" , ");
        printf("%d", s->data[i]);
    }
    printf("] ===> Stack(%d)\n", s->top);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10
    Stack *s = getStack(5);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int tval = top(s);
                printf("Push val(%d) to Stack-top(%d) is %s !\n", val, tval, push(s, val) ? "YES" : "NO");
            } break;
            case 3: {
                int tval = top(s);
                printf("Pop a val(%d) from Stack-top is %s !\n", tval, pop(s) ? "YES" : "NO");
            } break;
        }
        output(s);
    }
    clear(s);
    #undef max_op
    return 0;
}
