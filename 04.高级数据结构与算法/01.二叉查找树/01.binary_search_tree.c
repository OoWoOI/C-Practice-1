/*************************************************************************
	> File Name: 01.binary_search_tree.c
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Aug 2023 09:48:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define KEY(n) ((n) ? (n->key) : (-1))

//二叉搜索树:初始化, 插入，删除，遍历，销毁
typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

//初始化：获取新节点
Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
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

//获取前驱节点
Node *preNode(Node *root) {
    Node *tmp = root->lchild;
    while (tmp->rchild) tmp = tmp->rchild;
    return tmp;
}

//删除
Node *erase(Node *root, int val) {
    if (root == NULL) return root;
    if (root->key < val) {
        root->rchild = erase(root->rchild, val);
    } else if (root->key > val) {
        root->lchild = erase(root->lchild, val);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            //当度为0、1时
            Node *tmp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return tmp;
        } else {
            //当度为2时
            Node *tmp = preNode(root);
            root->key = tmp->key;
            root->lchild = erase(root->lchild, tmp->key);
            return root;
        }
    }
    return root;
}


//遍历
void output(Node *root) {
    if (root == NULL) return ;
    printf("((%3d) | (%3d) : (%3d) )\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
    return ;
}

//销毁
void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}


int main () {
    
    Node *root = NULL;
    int key;
    //插入
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("=============== insert val(%d) to BST ============\n", key);
        root = insert(root, key);
        output(root);
    }
    
    //删除
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("=============== erase val(%d) from BST ===========\n", key);
        root = erase(root, key);
        output(root);
    }
    clear(root);
    return 0;
}
