/*************************************************************************
	> File Name: 05.binary_theard_in.c
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Aug 2023 09:18:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NORMAL 0
#define THREAD 1

//先序遍历线索化
typedef struct Node {
    int key;
    struct Node *rchild, *lchild;
    int rtag, ltag;
}Node;

//获取新节点
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag;
    return p;
}

//插入
Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    return root;
}

//前序遍历
void in_order(Node *root) {
    if(root == NULL) return ;
    printf("%d ", root->key);
    if (root->ltag == NORMAL) in_order(root->lchild);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return ;
}
//线索化建立
void build_thread(Node *root) {
    if (root == NULL) return ; 
    static Node *pre = NULL;  
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }

    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    if (root->ltag == NORMAL) build_thread(root->lchild);
   if (root->rtag == NORMAL) build_thread(root->rchild);
    return ;
}

//输出
void output(Node* root) {
    if (root == NULL) return;
    Node *p = root;
    while (p) {
        printf("%d ", p->key);
        if (p->ltag == NORMAL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    return ;
}

//销毁
void clear(Node *root) {
    if (root == NULL) return ;
    if (root->lchild == NORMAL) clear(root->lchild);
    if (root->rchild == NORMAL) clear(root->rchild);
    free(root);
    return ;
}


int main() {
    srand(time(0));
    #define max 20
    Node *root = NULL;
  //  int ans[10] = {10, 8, 12, 7, 9, 5, 11, 13};
    for (int i = 0; i < max; i++) {
       root = insert(root, rand() % 100);
    }
    in_order(root), printf("\n");
    //线索化建立
    build_thread(root);
    output(root), printf("\n");
    #undef max
    return 0;
}
