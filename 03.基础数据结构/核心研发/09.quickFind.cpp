/*************************************************************************
	> File Name: 09.quickFind.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:30:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *color;
    int size;
}UnionSet;

//初始化
UnionSet *InitSet(int size){
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * (size + 1));
    u->size = size + 1;
    for (int i = 0; i < u->size; i++) {
        u->color[i] = i;
    }
    return u;
}

//查找
int find(UnionSet *u, int indx) {
    return u->color[indx];
}

//合并
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    int acolor = find(u, a);
    for (int i = 0; i < u->size; i++) {
        if (find(u, i) == acolor) u->color[i] = u->color[b];
    }

    return 1;
}

//销毁
void freeSet(UnionSet *u) {
    if (u == NULL) return;
    free(u->color);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = InitSet(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch(a) {
            case 1: 
                merge(u, b, c);
                break;
            case 2:
                printf("%s\n", find(u, b) ==find(u, c) ? "Yes" : "No");
                
        }
    }
    
    freeSet(u);

    return 0;
}
