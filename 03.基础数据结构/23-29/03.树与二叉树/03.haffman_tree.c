/*************************************************************************
	> File Name: 03.haffman_tree.c
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Aug 2023 08:21:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 100

#define swap(a, b) {\
    __typeof(a) __tmp = a; a = b; b = __tmp;\
}



//哈夫曼编码树

//树节点:字符 + 指针
typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

//数据:字符 + 出现频次
typedef struct Data {
    char ch;
    double p;
} Data;

typedef struct Code {
    char ch;
    char *str;
}Code;

//哈夫曼树结构
typedef struct HaffManTree {
    Node *root;
    int n;
    Code *codes;
} HaffManTree;

Data arr[MAX_N + 5]; 

//获取新的节点
Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

//获取一颗HaffMan树
HaffManTree *getNewTree(int n) {
    HaffManTree *tree = (HaffManTree *)malloc(sizeof(HaffManTree));
    tree->root = NULL;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->n = n;
    return tree;
}

//插入排序
void insertSort(Node **arr, int n) {
    for (int i = n; i >= 1; i--) {
        if (arr[i]->p > arr[i - 1]->p) {
            swap(arr[i], arr[i - 1]);
            continue;
        }
        break;
    }
    return ;
}

//获取每个字符的编码
int extractCodes(Node *root, Code *codes, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        codes[k].ch  = root->ch;
        codes[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], codes, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], codes, k + delta, l + 1, buff);
    return delta;
}


//构建HaffMan树
HaffManTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node*) * n);
    
    //获取待编码的字符节点数组
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    //排序调整字符出现频次的顺序 多 -> 少
    for (int i = 1; i < n ; i++) {
        insertSort(nodes, i);
    }

    //合并相同
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = p->next[0]->p + p->next[1]->p;
        nodes[i - 1] = p;
        insertSort(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffManTree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
    free(buff);
    free(nodes);
    return tree;
}


int main(){
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];  
    }
    HaffManTree *tree = build(arr, n);
    for (int i = 0; i < tree->n; i++) {
        printf("%c | %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
