/*************************************************************************
	> File Name: 06.heap.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:28:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct heap{
    int *data;
    int cnt;
    int size;
}heap;


//初始化堆结构
heap *init_heap(int size) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->data = (int *)malloc(sizeof(int) * size);
    h->size = size;
    h->cnt = 0;
    return h;
}

#define swap(a, b) {\
    __typeof(a) __a = a; a = b; b = __a;\
}

//入堆
int push(heap *h, int val) {
    if (h == NULL || h->size == h->cnt) return 0;
    h->data[++h->cnt] = val;
    //向上调整
    int ind = h->cnt;
    while ((ind >> 1) > 0 && (h->data[ind] > h->data[ind >> 1])) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    //    printf("ss\n");
    }
    return 1;
}

//出堆
int pop(heap *h) {
    if (!h || h->cnt == 0)
        return 0;
    
    //交换首尾元素位置
    swap(h->data[1], h->data[h->cnt])
    h->cnt--;
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;
        if (h->data[l] > h->data[tmp]) tmp = l;
        if (r <= h->cnt && h->data[tmp] < h->data[r]) tmp = r;
        if (tmp == ind) break;
        swap(h->data[tmp], h->data[ind]);
        ind = tmp;
    }

    return 1;
}

//销毁堆
void clear_heap(heap *h) {
    if (!h) 
        return ;
    free(h->data);
    free(h);
    return ;
}

//输出
void output(heap *h) {
    if (!h)
        return ;
    printf("[");
    for (int i = 1; i <= h->cnt; i++) {
        i != 1 && printf(", ");
        printf("%d", h->data[i]);
    }
    printf("] ===> %d\n", h->size);
    return ;
}

int main() {
    #define MAX_OP 10 
    srand(time(0));
    heap *h = init_heap(MAX_OP);
    printf("随机元素: ");
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(h, val);
        i && printf(" ");
        printf("%d", val);
    }
    printf("\n");

    for (int i = 0; i < MAX_OP; i++) {
        pop(h);
    }
  //  h->cnt = 10;
    //输出堆元素
    output(h);
   
    clear_heap(h);
    #undef MAX_OP
    return 0;
}
