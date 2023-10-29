/*************************************************************************
	> File Name: 12.hash_table.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Oct 2023 09:20:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable{
    Node **data;
    int size;
}HashTable;

HashTable *Init_Hash(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node **)malloc(sizeof(Node *) * size);
    h->size = size;
    return h;
}


Node *getNewNode(char *str) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = NULL;
    return p;
}

int BDKhash(char *str) {
    int seed = 31, hash = 0;
    while (*str) {
        hash = hash * seed + str[0];
        str++;
    }

    return hash & 0x7ffffff;
}

//插入
int insert(HashTable *h, char *str) {
    if (h == NULL) return 0;
    int hash = BDKhash(str);
    int ind = hash % h->size;
    if (h->data[ind]) {
        Node *p = h->data[ind];
        while (p->next) {
            p = p->next;
        }
        p->next = getNewNode(str);
    } else {
        h->data[ind] = getNewNode(str);
    }
    return 1;
}

//查找
int search(HashTable *h, char *str) {
    if (h == NULL) return 0; 
    int hash = BDKhash(str);
    int ind = hash % h->size;
    if (!h->data[ind]) return 0;
    Node *p = h->data[ind];
    while (p) {
        if (strcmp(p->str, str) == 0) return 1;;
        p = p->next;
    }
    return 0;
}

//销毁
void clearNode(Node *node) {
    if (node == NULL) return ;
    Node *p = node;
    while (p) {
        Node *q = p;
        p = p->next;
        free(q);
    }
    return ;
}

void clear(HashTable *h) {
    if (h == NULL) return;
    for (int i = 0; i < h->size; i++) {
        clearNode(h->data[i]);
    }
    free(h);
    return ;
}



int main() {
    srand(time(0));    
    #define max_op 10
    HashTable *h = Init_Hash(max_op);
    int op;
    char str[1024];
    printf("请输入操作选项【0（插入）/ 1（查找）】：");
    while (~scanf("%d", &op)) {
        switch(op) {
            case 0: {
                printf("请输入待插入的字符串：");
                scanf("%s", str);
                int ret = insert(h, str);
                printf("insert the str %s is %s", str, ret ? "success" : "failure");
                break;
            }
            case 1: {
                printf("请输入带查找的字符串：");
                scanf("%s", str);
                int ret = search(h, str);
                printf("search reasult is %s", ret ? "success" : "failure");
                break;
            }
            default:{
                printf("功能暂时不支持!");
                break;
            }
        }
        printf("\n");
        memset(str, 0, 1024);
        printf("请输入操作选项【0（插入）/ 1（查找）】：");
    }

    return 0;
}
