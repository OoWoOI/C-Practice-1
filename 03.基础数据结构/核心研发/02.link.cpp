/*************************************************************************
	> File Name: 02.link.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:28:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct LinkNode {
    int val;
    struct LinkNode *next;
}Node;

typedef struct LinkList {
    Node *head;
    int len;
}LinkList;

//初始化：链表初始化, 插入,  删除,  查找,  输出, 销毁
Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

//初始化链表头结点
LinkList *init_LinkList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head = getNewNode(0);
    l->len = 0;
    return l;
}

//插入结点
int insert(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (l->len < ind || ind < 0) return 0;//非法操作
    Node *p = l->head, *q;
    while (ind--) {
        p = p->next;
    }
    q = p->next;
    p->next = getNewNode(val);
    p->next->next = q;
    l->len += 1;
    return 1;
}

//删除
int erase(LinkList *l, int ind) {
    if (l == NULL) return 0;
    if (l->len <= ind || ind < 0) return 0;
    Node *p = l->head, *q;
    while (ind--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    l->len -= 1;
    return 1;
}

//销毁

void clear(LinkList *l) {
    if (l == NULL) return ;
    Node *p = l->head, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

//输出结点信息
void output(LinkList *l) {
    if (l == NULL) return ;
    printf("[");
    int flag = 0;
    for (Node *p = l->head->next; p; p = p->next) {
        if (flag) printf(" -> ");
        printf("%d", p->val);
        flag = 1;
    }
    printf("] ==> %d\n", l->len);
    return ;
}


int main() {
   srand(time(0));
   #define max_op 20
   LinkList *l = init_LinkList();
   for (int i = 0; i < max_op; i++) {
       int op = rand() % 4;
       int val = rand() % 100;
       int ind = rand() % (l->len + 1);
       switch (op) {
           case 0:
           case 1:
           case 2: {
               int ret = insert(l, ind, val);
               printf("insert val %d to ind %d is %s !\n", val, ind, ret ? "successfuly" : "fail");
               break;
           }
           case 3: {
               int ret = erase(l, ind);
               printf("erase ind %d from linklist is %s!\n", ind, ret ? "successfuly" : "fail");
               break;
           } 
       }
       output(l);
   }
    clear(l);
    #undef max_op
   return 0;
}
