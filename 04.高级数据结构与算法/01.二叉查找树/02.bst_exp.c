/*************************************************************************
	> File Name: 02.bst_exp.c
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Aug 2023 01:45:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define KEY(n) ((n) ? (n->key) : (-1))
#define CNT(n) ((n) ? (n->cnt) : (0))


//扩展：使用二叉搜索树查找固定的X值、求第k小值、求区间[l, r]范围内的值
typedef struct Node {
    int key, cnt;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->cnt = 1;
    return p;
}//获取新节点


void update_height(Node *root) {
    if (root == NULL) return ;    
    root->cnt = CNT(root->lchild) + CNT(root->rchild) + 1;
    return ;
}//更新节点数量

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) {
        root->rchild = insert(root->rchild, val);
    } else {
        root->lchild = insert(root->lchild, val);
    }
    update_height(root);
    return root;
}//插入

Node *preNode(Node *root) {
    Node *tmp = root->lchild;
    while (tmp->rchild) tmp = tmp->rchild;
    return tmp;
}//前驱节点


Node *erase(Node *root, int val) {
    if (root == NULL) return root;
    if (root->key < val) {
        root->rchild = erase(root->rchild, val);
    } else if (root->key > val) {
        root->lchild = erase(root->lchild, val);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *tmp = root->lchild ? root->lchild : root->rchild;
            free(root);
            root = tmp;
        } else {
            Node *tmp = preNode(root);
            root->key = tmp->key;
            root->lchild = erase(root->lchild, tmp->key);
        }
    }
    update_height(root);
    return root;
}//删除

//寻找固定值X
Node* search_X(Node *root, int x) {
    if (root == NULL) return NULL;
    if (root->key == x) return root;
    if (root->key < x) return search_X(root->rchild, x);
    return search_X(root->lchild, x);
}

//查找第K小元素
Node* find_K(Node *root, int k) {
    if (root == NULL || CNT(root) < k) return NULL;
    if ((CNT(root->lchild)) + 1 == k) return root;
    if ((CNT(root->lchild)) + 1 > k) return find_K(root->lchild, k);
    return find_K(root->rchild, k - (CNT(root->lchild) + 1));
}

//查找[l, r]范围内的元素
void output_range(Node *root, int l, int r, int *n, int *num) {
    if (root == NULL) return ;
    output_range(root->lchild, l, r, n, num);
    if(l <= root->key && r >= root->key) { 
        num[(*n)++] = root->key;
    } 
    output_range(root->rchild, l, r, n, num);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    printf("((%3d) | (%3d) : (%3d))\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
    return ;
}//遍历

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}//销毁节点

int main() {
    int key;
    Node *root = NULL;
    //插入元素
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("==================== insert val(%d) to BST =====================\n", key);
        root = insert(root, key);
    }

    output(root);

    //删除元素
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("==================== erase val(%d) from BST =====================\n", key);
        root = erase(root, key);
    }
    
    output(root);

    //查找X值
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("===================== search X(%d) from BST =====================\n", key);
        Node *tmp = search_X(root, key);
        printf("search val(%d) from BST is %s!\n", key, tmp ? "find it" : "not find it");
    }

    //查找第K小值
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("===================== find kth(%d) from BST =====================\n", key);
        Node *tmp = find_K(root, key);
        printf("find k(%d)th from BST is %d!\n",key, KEY(tmp));
        printf("cnt = %d\n", CNT(tmp));
       // output(root);
    }
    
    //查找范围内的值
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        if (l == -1 && r == -1) break;
        printf("===================== find [%d, %d] from BST ======================\n", l, r);
        printf("[");
        int n = 0, num[CNT(root) + 5];
        output_range(root, l, r, &n, num);
        for (int i = 0; i < n; i++) {
            i && printf(", ");
            printf("%d", num[i]);
        }
        printf("] ===> num[%d]\n", n);
    }
    clear(root);
    return 0;
}
