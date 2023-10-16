/*************************************************************************
	> File Name: 02.gtable_turn_binary_tree.c
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Aug 2023 09:55:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX_N 100
#define KEY(n) ((n) ? (n->key) : (0))

//广义表转二叉树
typedef struct Node {
    char key;
    struct Node *lchild, *rchild;
}Node;
 
//树结构
typedef struct Tree {
    Node *root;
    int cnt;
}Tree;

//辅助栈
typedef struct Stack{
    Node** data;
    int top;
}Stack;

//实现栈功能
Stack* init_Stack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node**)malloc(sizeof(Node*) * (size));
    s->top = -1;
    return s;
}

//判空
int empty(Stack *s) {
    return s->top == -1;
}

//栈顶元素
Node *top(Stack *s) {
    return s->data[s->top];
}

//入栈
void push(Stack *s, Node *val){
    if (s == NULL) return ;
    s->data[++s->top] = val;
    return ;
}

//出栈
void pop(Stack *s) {
    if (empty(s)) return ;
    s->top--;
    return ;
}

//销毁栈
void clear_Stack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

//获取新节点
Node* getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    return p;
}

//获取一颗空树
Tree *init_Tree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->cnt = 0;
    return tree;
}

//建立树的过程
Node* build(char *str, int *num) {
    Node *p = NULL, *tmp = NULL;
    Stack *s = init_Stack(MAX_N + 5);
    int flag = 0;
    while (str[0]) {
        switch(str[0]) {
            case '(': {
                push(s, tmp);
                flag = 0;
                tmp = NULL;
            } break;
            case ')': {
                p = top(s);
                pop(s);
            } break;
            case ' ': {

            } break;
            case ',':{
                flag = 1;
                tmp = NULL;
            } break;
            default : {
                tmp = getNewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = tmp;
                } else if (!empty(s) && flag == 1) {
                    top(s)->rchild = tmp;
                }
                ++(*num);
            } break;
        }
        str++;
    }
    clear_Stack(s);
    if (tmp && !p) p = tmp;
    return p;
}

//销毁树
void clear_node(Node *root) {
    if (root == NULL) return ;
    clear_node(root->lchild);
    clear_node(root->rchild);
    free(root);
    return ;
}

void clear_tree(Tree* tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

//中序遍历
void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("((%c) | (%c), (%c))\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->rchild);
    return ;
}

int main() {
    char str[MAX_N + 5];
    scanf("%[^\n]s", str);
    Tree *tree = init_Tree();
    int num = 0;
    //广义表转二叉树
    tree->root = build(str, &num);
    tree->cnt = num;
    printf("tree[%d] ===>\n", num);
    output(tree->root);


    clear_tree(tree);
    return 0;
}
