/*************************************************************************
	> File Name: 01.Vector.c
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Aug 2023 09:52:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Vector {
    int *data;
    int cnt, size;
}Vector;
//顺序表:初始化、插入、删除、遍历、销毁、扩容

//初始化
Vector *getNewVector(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)calloc(sizeof(int), size);
    v->size = size;
    v->cnt = 0;
    return v;
}

//扩容
int expand(Vector *v) {
    int exp_size = v->size;
    int *p;
    while (exp_size) {
        p = (int *)realloc(v->data, (exp_size + v->size));
        if (p) break;
        exp_size /= 2;
    }
    if (p == NULL) return 0;
    v->data = p;
    v->size += exp_size;
    return 1;
}

//插入
int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->cnt) return 0;//插入位置不合法
    if (v->cnt >= v->size) {
        if (!expand(v)) return 0;
        printf("expand is successful !\n");
    }
    for (int i = v->cnt; i > ind; i--) {
        v->data[i] = v->data[i - 1];    
    }
    v->data[ind] = val;
    v->cnt++;
    return 1;
}

//删除
int erase(Vector *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->cnt) return 0;
    for (int i = ind; i < v->cnt; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->cnt--;
    return 1;
}

//销毁
void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

//遍历
void output(Vector *v) {
    if (v == NULL) return ;
    printf("[");
    for (int i = 0; i < v->cnt; i++) {
        i && printf(",");
        printf("%d", v->data[i]);
    }
    printf("] ===> V[%d]\n", v->cnt);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10
    Vector *v = getNewVector(max_op);
    int val, op, ind;
    for (int i = 0; i < max_op; i++) {
        ind = rand() % (v->cnt + 1);
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert val(%d) to Vector ind(%d) %s!\n", val, ind, insert(v, ind, val) ? "YES" : "NO");
            }break;
            case 3: {
                printf("erase ind(%d) from Vector is %s!\n", ind, erase(v, ind) ? "YES" : "NO");
            }break;
        }
        output(v);
    }
    #undef max_op
    clear(v);
    return 0;
}
