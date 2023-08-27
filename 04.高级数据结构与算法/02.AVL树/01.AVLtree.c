/*************************************************************************
	> File Name: 01.AVLtree.c
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Aug 2023 03:27:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


//二叉平衡查找树：AVL
//高度控制（平衡条件）：abs(h(root->left) - h(root->right)) <= 1)
typedef struct Node {
    int key, h;
    struct Node *rchild, *lchild;
}Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->h = 1;
    p->lchild = p->rchild = NULL;
    return p;
}//获取新节点


void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}//销毁

int main() {


    return 0;
}
