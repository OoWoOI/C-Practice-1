/*************************************************************************
	> File Name: 01.binary_tree.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Aug 2023 08:39:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_op 10 

#define KEY(n) ((n) ? (n->key) : (-1))

#define TEST(func) {\
    printf("[");\
    func(tree->root);\
    printf("NULL]====> %s(%d)\n",#func, tree->cnt);\
}

/*
 *二叉树：
 *  （1）初始化
 *  （2）插入
 *  （3）遍历：前、中、后、层序
 *  （4）销毁
 * */

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int cnt;
} Tree;

//获取新节点
Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = val;
    node->lchild = node->rchild = NULL;
    return node;
}

//获取一颗新树
Tree* getTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->cnt = 0;
    return tree;
}

//插入
Node* __insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key > val) root->lchild = __insert(root->lchild, val);
    else root->rchild = __insert(root->rchild, val);
    return root;
}

void insert(Tree* tree, int val) {
    if (tree == NULL) return ;
    tree->root = __insert(tree->root, val);
    tree->cnt++;
    return ;
}

//遍历

//前序遍历
void preOrder(Node *root) {
    if (root == NULL) return ;
    printf("%d => ", root->key);
    preOrder(root->lchild);
    preOrder(root->rchild);
    return ;
}

//中序遍历
void midOrder(Node *root) {
   if (root == NULL) return ;
    midOrder(root->lchild);
    printf("%d => ", root->key);
    midOrder(root->rchild);
    return ;
}

//后序
void lastOrder(Node *root) {
    if (root == NULL) return ;
    lastOrder(root->lchild);
    lastOrder(root->rchild);
    printf("%d => ", root->key);
    return ;
}

//辅助队列
typedef struct Queue {
    Node **data;
    int head, tail,cnt, size;
} Queue;

//初始化新队列
Queue *getQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node** )malloc(sizeof(Node *) * (size + 5));
    q->head = q->tail = q->cnt = 0;
    q->size = size;
    return q;
}

//判断空操作
int empty(Queue *q) {
    return q->cnt == 0;
}

//获取队首元素
Node *top(Queue *q) {
    return q->data[q->head];
}

//入队
void push(Queue *q, Node *root) {
    if (q == NULL || q->cnt == q->size) return ;
    q->data[q->tail++] = root;
    if (q->tail >= q->size) q->tail -= q->size;
    q->cnt++;
    return ;
}

//出队
void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
    if (q->head >= q->size) q->head -= q->size;
    q->cnt--;
    return ;
}


//销毁队列
void clearQueue(Queue *q) {
    if (q == NULL) return ;
    free(q);
    return ;
}


//层序遍历
void layeOrder(Node *root) {
    if (root == NULL) return ;
    Queue *q = getQueue(max_op + 5);
    push(q, root);
    while (!empty(q)) {
        Node *tmp = top(q);
        int start = q->head, end = q->tail;
        printf("%d => ", tmp->key);
//        for (int i = start; i < end; i++) {
            if (tmp->lchild) push(q, tmp->lchild);
            if (tmp->rchild) push(q, tmp->rchild);
            pop(q);
  //      }
    }

    //for (int i = 0; i < q->tail; i++) printf("%d => ", q->data[i]->key);
    clearQueue(q);
    return ;
}

void root_out(Node *root) {
    if (root == NULL) return ;
    root_out(root->lchild);
    printf("[(%3d) | (%3d) : (%3d) ]\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    root_out(root->rchild);
    return ;
}

//输出
void output(Tree *tree) {
    if (tree == NULL) return;
    //root_out
    root_out(tree->root);
    //先序遍历
    TEST(preOrder);
    //中序
    TEST(midOrder);
    //后序
    TEST(lastOrder);
    //层序
    TEST(layeOrder);
    return ;
}


//销毁树结点
void clearNode(Node *root) {
    if (root == NULL) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return ;
}

//销毁树结构
void clearTree(Tree *tree) {
    if (tree == NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

int main() {
    srand(time(0));
    Tree *tree = getTree();
    int val;
    for (int i = 0; i < max_op; i++) {
        val = rand() % 100;
        insert(tree, val);
    }   
    output(tree);
    clearTree(tree);
    return 0;
}
