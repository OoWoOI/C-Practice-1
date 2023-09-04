/*************************************************************************
	> File Name: 06.binary_theard_last.c
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Sep 2023 07:55:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define NORMAL 0
#define THREAD 1

//二叉线索树的后序遍历
typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
    int rtag, ltag;
}Node;

//获取一个新节点
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    p->rtag = p->ltag = NORMAL;
    return p;
}

//插入新节点
Node* insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    return root;
} 

//线索化
void bulidThread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    bulidThread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    
    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    bulidThread(root->rchild);
    return ;
}

//销毁
void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return;
}

//后序遍历
void lastOrderByDef(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) lastOrderByDef(root->lchild);
    if (root->rtag == NORMAL) lastOrderByDef(root->rchild);
    printf("%d ", root->key);
    return ;
}

Node* most_left(Node *root) {
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void lastOrderByThread(Node *root) {
    if (root == NULL) return ;
    Node *p = root, *pre = NULL;
    while (p) {
        if (p->rtag == THREAD || p->rchild == NULL) {
            printf("%d ", p->key);
            p = p->rchild;
        } else {
            pre = p->rchild;
            while (pre->ltag == NORMAL && pre->lchild) {
                pre = pre->lchild;
            }
            if (pre->ltag == NORMAL) {
                pre->lchild = p;
                p = p->rchild;
            }
        }

    }

    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    //插入数据
    for (int i = 0; i < max_op; i++) root = insert(root, rand() % 100);
    //递归实现后序边
    lastOrderByDef(root), printf("\n");
    //线索化建立
    bulidThread(root);
    lastOrderByThread(root), printf("\n");
    //销毁树
    clear(root);
    #undef max_op
    return 0;
}
