/*************************************************************************
	> File Name: 73.湖泊.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 09:12:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *father;
    int size;
}UnionSet;

UnionSet *initSet(int n){
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = n + 1;

    for (int i = 0; i < u->size; i++) {
        u->father[i] = i;
    }
    
    return u;
}

void freeSet(UnionSet *u) {
    if (!u) return ;
    free(u->father);
    free(u);
    return ;
}

int find(UnionSet *u, int indx) {
    return u->father[indx] = u->father[indx] == indx ? indx : find(u, u->father[indx]);
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    u->father[fa] = fb;
    return 1;
}

int m = 0;
int indx(int i, int j) {return i * m + j + 1;}

int main(){
    int n;
    scanf("%d%d", &n, &m);

    UnionSet *u = initSet(m * n + 5);
    char (*arr)[m + 5] = malloc(sizeof(char) * (m + 5) * (n + 5));
    
    for (int i =0; i < n; i++) scanf("%s", arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') continue;
            if (j > 0 && arr[i][j - 1] == 'O') merge(u, indx(i, j), indx(i, j - 1));
            if (i > 0 && arr[i - 1][j] == 'O') merge(u, indx(i, j), indx(i - 1, j));
            if (i == 0 || i == n - 1) merge(u, indx(i, j), 0);
            if (j == 0 || j == m - 1) merge(u, indx(i, j), 0);

        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') continue;
            sum += find(u, indx(i, j)) != find(u, 0);
        }
    }
    printf("%d\n", sum);
    return 0;
}
