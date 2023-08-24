/*************************************************************************
	> File Name: 02.LinkList.c
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Aug 2023 11:17:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//链表:结点初始化、删除、插入、遍历、查找、销毁
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkList {
    Node *head;
    int len;
} LinkList;

//获取新结点
Node* getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->next = NULL;
    return p;
}

//获取新链表
LinkList* getNewLinkList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head = getNewNode(0);
    l->len = 0;
    return l;
}

//插入
int insert(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->len) return 0;
    Node *p = l->head, *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next =getNewNode(val);
    p->next->next = q;
    l->len++;
    return 1;
}

//删除
int erase(LinkList *l, int ind) {
    printf("ind = %d, len = %d\n", ind, l->len);
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->len) return 0;
    Node *p = l->head, *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    l->len--;
    return 1;
}

//查找
int findVal(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->len) return 0;
   Node *p = l->head;
    while (ind--) p = p->next;
    return p->next->data == val;
}


//销毁结点
void clearNode(Node *head) {
    if (head == NULL) return ;
    clearNode(head->next);
    free(head);
    return ;
}

//销毁链表
void clear(LinkList *l) {
    if (l == NULL) return ;
    clearNode(l->head);
    free(l);
    return ;
}

//遍历
void output(LinkList *l) {
    if (l == NULL) return ;
    printf("[");
    int flag = 0;
    for (Node *p = l->head->next; p; p = p->next) {
        flag  && printf(" -> ");
        printf("%d", p->data);
        flag = 1;
    }
    printf("] ====> LinkList[%d]\n", l->len);
    return ;
}


int main() {
    #define max_op 10
    int ind, op, val;
    LinkList *l = getNewLinkList();
    srand(time(0));
    for (int i = 0; i < max_op; i++) {
         ind = rand() % (l->len + 1);
         op = rand() % 5;
         val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert val(%d) to LinkLis in ind(%d) is %s!\n", val, ind, insert(l, ind, val) ? "YES" : "NO");
            } break;
            case 3: {
                printf("erase one elem from LinkList in ind(%d) is %s!\n", ind, erase(l, ind) ? "YES" : "NO");
            } break;
            case 4: {
                //查看第ind位置的值是否等于val
                int flag = findVal(l, ind, val);
                printf("findVal a val(%d) from LinkList in ind(%d) is %s!\n", val, ind, flag ? "YES" : "NO");
            } break;
        }
        output(l);
    }
    clear(l);
    #undef max_op
    return 0;
}
