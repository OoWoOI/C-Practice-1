/*************************************************************************
	> File Name: 01.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:13:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//线性表：初始化，插入、删除、查找、销毁、

typedef struct Vector{
    int *data;
    int size;
    int len;
}Vector;

Vector *init(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * size);
    v->size = size;
    v->len = 0;
    return v;
}

int exp(Vector *v) {
    int exp_size = v->size;
    int *p = NULL;
    while (exp_size) {
        p = (int *)realloc(v->data , sizeof(int) *  (v->size + exp_size));//重新分配空间
        if (p) break;
        exp_size /= 2;
    }

    if (!p) return 0;//空间分配失败
    v->data = p;
    v->size += exp_size;//更新空间容量
    return 1;
}

//插入元素
int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->len) return 0;
    if (v->len + 1 == v->size) {
        //扩容
        if (!exp(v)) {
            printf("expand fualt!\n");
            return 0;//空间分配失败
        }
        printf("expand successfuly!\n");
    }
    
    memcpy(v->data + ind + 1, v->data + ind, sizeof(int) * (v->len - ind) );
    v->data[ind] = val;
    v->len += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (!v) return 0;
    if (ind < 0 || ind >= v->len) return 0;//非法操作
    memcpy(v->data + ind, v->data + ind + 1, sizeof(int) * (v->len - ind - 1));
    v->len -= 1;
    return 1;
}
//输出
void output(Vector *v) {
    if (v == NULL) return ;
    printf("[");
    for (int i = 0; i < v->len; i++) {
        i && printf(", ");
        printf("%d", *(v->data + i));
    }
    printf("] ===> %d, %d\n", v->len, v->size);
    return ;
}


//销毁
void clear(Vector *v) {
    if (!v) return ;
    if (v->data) free(v->data);
    free(v);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Vector *v = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        int ind = rand() % (v->len + 1);
        switch (op) {
            case 0:          
            case 1:
            case 2:{
                int ret = insert(v, ind, val);
                printf("insert val %d to ind %d is %s !\n", val, ind, ret ? "successfuly" : "fail");
                break;
            }
            case 3: {
                int ret = erase(v, ind);
                printf("erase ele from ind %d is %s !\n", ind, ret ? "successfuly" : "fail");
                break;
            }   
        }
        output(v);
    }
    clear(v);
    #undef max_op
    return 0;
}
