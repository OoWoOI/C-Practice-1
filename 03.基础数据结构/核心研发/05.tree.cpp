/*************************************************************************
	> File Name: 05.tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:28:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//二叉排序树

//结点
typedef struct Node {
    int val;
    struct Node *left, *right;
}Node;

//树结构
typedef struct Tree {
    Node *root;
    //int cnt;
}Tree;

//初始化
Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

Tree *init() {
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    //t->cnt = 0;
    return t;
}

//插入结点
Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->val == val) return root;
    if (root->val < val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    } 
    return root;
}

//前序遍历
void pre_oder(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    pre_oder(root->left);
    pre_oder(root->right);
    return ;
}

//中序遍历
void mid_order(Node *root) {
    if(root == NULL) return ;
    mid_order(root->left);
    printf("%d ", root->val);
    mid_order(root->right);
    return ;
}

//后序遍历
void last_order(Node *root) {
    if (root == NULL) return ;
    last_order(root->left);
    last_order(root->right);
    printf("%d ", root->val);
    return ;
}

//销毁
void clearNode(Node *root) {
    if (root == NULL) return ;
    clearNode(root->left);
    clearNode(root->right);
    free(root);
    return ;
}

void clear(Tree *t) {
    if (t == NULL) return ;
    clearNode(t->root);
    free(t);
    return ;
}

int main() {
    srand(time(0));
    Tree *t = init();
    #define max_op 20
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        t->root = insert(t->root, val);
    }
    //前序遍历
    printf("前序遍历: \n");
    pre_oder(t->root);
    printf("\n");
    //中序遍历
    printf("中序遍历: \n");
    mid_order(t->root);
    printf("\n");
    //后序遍历
    printf("后序遍历: \n");
    last_order(t->root);
    printf("\n");
    clear(t);
    #undef max_op
    return 0;
}
