/*************************************************************************
	> File Name: 04.binary_theard_tree.c
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Aug 2023 09:02:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NORMAL 0
#define THREAD 1

//二叉线索树
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

//插入元素
Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    return root;
}

//二叉树线索化建立
void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node* pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = root;
        root->ltag = THREAD;
    }
    
    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);//往左边去
    return ;
}

Node *most_left(Node *root) {
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
} 

//中序线索遍历
void output_theard(Node *root) {
    if (root == NULL) return ;
    Node *p = most_left(root);
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return ;
}

//中序遍历
void mid_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) mid_order(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) mid_order(root->rchild);
    return ;
}

//销毁线索树
void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    int val;
    for (int i = 0; i < max_op; i++) {
        val = rand() % 100;
        root = insert(root, val);
    }
    mid_order(root),printf("\n");
    build_thread(root);
    output_theard(root), printf("\n");
    clear(root);
    #undef max_op
    return 0;
}
