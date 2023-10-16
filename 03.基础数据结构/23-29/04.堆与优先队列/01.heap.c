/*************************************************************************
	> File Name: 01.heap.c
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Aug 2023 07:39:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __tmp = a; a = b; b = __tmp;\
}

typedef struct Heap {
    int *data;
    int cnt, size;
} Heap;

//堆与优先队列：数组实现
/*
* 结构操作：
*   1.初始化
*   2.入堆
*   3.出堆
*   4.遍历
*   5.销毁
* */

Heap *getNewHeap(int size) {
    Heap* h = (Heap* )malloc(sizeof(Heap)); 
    h->data = (int *)malloc(sizeof(int) * (size + 5));
    h->cnt = 0;
    h->size = size;
    return h;
}/*初始化*/

//获取根节点
int front(Heap *h) {
    if (h->cnt == 0) return -1;
    return h->data[1];
}

//入堆
int insert(Heap *h, int val) {
    if (h == NULL) return 0;
    if (h->cnt == h->size - 1) return 0; 
    h->data[++h->cnt] = val;
    
    //入堆后向上调整
    int ind = h->cnt;
    while (ind >> 1 && h->data[ind] > h->data[ind >> 1]) {
        swap(h->data[ind], h->data[ind >> 1]); 
        ind >>= 1;
    }
    return 1;
}


//出堆向下调整
int delete(Heap *h) {
    if (h == NULL || h->cnt == 0) return 0;
    swap(h->data[1], h->data[h->cnt]);
    h->cnt--;
    int ind = h->cnt;
    while (ind << 1 <= h->cnt) {
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;
        if (h->data[l] > h->data[tmp]) tmp = l;
        if (r <= h->cnt && h->data[r] > h->data[tmp]) tmp = r;
        if (ind == tmp) break;
        swap(h->data[ind], h->data[tmp]);
        ind = tmp;
    }
    return 1;
}


void clear(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}/*销毁堆*/

void output(Heap *h) {
    if (h == NULL) return ;
    printf("[");
    for (int i = 1; i <= h->cnt; i++) {
        i != 1 && printf(", ");
        printf("%d", h->data[i]);
    }
    printf("] ==> Heap[%d]\n", h->cnt);
    return ;
}/*遍历*/

int main () {
    srand(time(0)); 
    int val, op;
    #define max_op 10
    Heap *h = getNewHeap(max_op);
    
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert val(%d) in the Heap is %s!\n", val, insert(h, val) ? "YES" : "NO");
            } break;
            case 3: {
                val = front(h);
                printf("delete front(%d) from the Heap is %s!\n", val,delete(h) ? "YES" : "NO");
            } break;
        }
        output(h);
    }
    #undef max_op
    clear(h);
    return 0;
}
