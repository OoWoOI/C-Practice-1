/*************************************************************************
	> File Name: 05.tree-thread-pre.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Oct 2023 10:36:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define THREAD 1
#define NOMORE 0

typedef struct Node {
    int val;
    struct Node *left, *right;
    int rtag, ltag;
}Node;

//获取新结点
Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    node->rtag = node->ltag = NOMORE;
    return node;
}

//插入结点
Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
//    if (root->val == val) return root;
    if (root->val < val) 
        root->right = insert(root->right, val);
    else 
        root->left = insert(root->left, val);
    return root;
}

//先序遍历
void in_order(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    in_order(root->left);
    in_order(root->right);
    return ;
}


//销毁一棵树
void clearTree(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NOMORE) clearTree(root->left);
    if (root->rtag == NOMORE) clearTree(root->right);
    free(root);
    return ;
}

//建立先序遍历线索化

Node *pre = NULL;

void build(Node *root) {
    if (!root) 
        return ;
    
    //找到最左边的结点
    if (!root->left) {
        root->left = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->right) {
        pre->right = root;
        pre->rtag = THREAD;
    }
    pre = root;
    //找到右子树
   if (root->ltag == NOMORE) build(root->left);
   if (root->rtag == NOMORE) build(root->right);
    return ;
}

//获取当前子树最左边的结点
Node *getMSTLEFT(Node *p) {
    while (p && p->ltag == NOMORE && p->left) 
        p = p->left;
    return p;
}


//线索化输出
void output(Node *root) {
    if (!root) return ;
    Node *p = root;
    
    while (p) {
        printf("%d ", p->val);
        if (p->ltag == NOMORE) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return ;
}


int main() {
    srand(time(0));
    Node *root = NULL;
    #define MAX_OP 20
    printf("数据插入: \n");
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;    
        root = insert(root, val);
        i && printf(" ");
        printf("%d", val);
    }
    printf("\n");
    printf("先序遍历递归: \n");
    in_order(root), printf("\n"); 
    
    //线索化建立
    build(root);
    printf("先序遍历线索化: \n");
    output(root), printf("\n");
    clearTree(root);
    #undef MAX_OP
    return 0;
}
