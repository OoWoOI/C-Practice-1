/*************************************************************************
	> File Name: 05.tree-table.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 08:16:29 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
}Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

//辅助栈结构用于括号匹配
typedef struct stack {
    Node **data;
    int top;
    int size;
}stack;

//获取一个新的栈结构
stack *getNewStack(int size) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (Node **)malloc(sizeof(Node *) * (size));
    s->size = size;
    s->top = -1;
    return s;
}

//栈结构判空操作
int is_empty(stack *s) {
    return s->top == -1;
}


//获取栈顶元素
Node *Top(stack *s) {
    if (is_empty(s)) return NULL;
    return s->data[s->top];
}

//扩容
int exp(stack *s) {
    int exp_size = s->size;
    Node **p = NULL;
    while (exp_size) {
        p = (Node **)realloc(s->data, sizeof(Node *) * (s->size + exp_size));    
        if (p) break;
        exp_size >> 1;
    } 
    if (!p) return 0;//扩容失败 
    free(s->data);
    s->data = p;
    s->size += exp_size;
    return 1;
}

//向栈空间插入元素
void push(stack *s, Node *root) {
    if (s == NULL) return ;
    if (s->top + 1 == s->size) {
        //扩容
        if (!exp(s)) {
            printf("expand size failure!\n");
            return ;
        }
        printf("expand size success!\n");

    }
    s->data[++(s->top)] = root;
    return ;
}

//向栈空间删除元素
void pop(stack *s) {
    if (s == NULL) return ;
    if (is_empty(s)) return ;//栈为空
    s->top -= 1;
    return ;
}

//销毁栈结构
void clear_stack(stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}


//广义表转二叉树
Node *table_to_tree(char *str) {
    Node *root = NULL, *p = NULL; 
    stack *s = getNewStack(strlen(str));
    int flag = 0;
    for (int i = 0; str[i]; i++) {
        switch(str[i]) { 
            case '(': {
                push(s, p);
                flag = 0;
                break;
            }
            case ',': {
                flag = 1;//右边
                break;
            }
            case ')': {
                root = Top(s);
                pop(s);
                break;
            }
            case ' ': 
                
                break;
            default :{

                int num = 0;
                while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
                    num = num * 10 + str[i] - '0';
                    i++;
                }
                i--;
                p = getNewNode(num); 
                if (!is_empty(s) && flag == 0) {
                    Top(s)->left = p;
                } else if (!is_empty(s) && flag == 1) {
                    Top(s)->right = p;
                }
                
                break;
            }
        }
    }
    //clear_stack(s);
   // if (tmp && p == NULL) p = tmp;
    return root;
}

//二叉树转广义表
void output(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->val);
    if (!root->left && !root->right) return;
    printf("(");
    output(root->left);
    printf(",");
    output(root->right);
    printf(")");
    return ;
}


int main() {
    char *str;
    scanf("%s", str);
    Node *root = table_to_tree(str);
    //将生成的树按照广义表输出
    output(root), printf("\n");
    return 0;
}
