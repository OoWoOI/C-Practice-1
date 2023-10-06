/*************************************************************************
	> File Name: EP24.c
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Oct 2023 09:04:54 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 10

int dnum[max_n];
int jump_num[max_n];

void init() {
    dnum[0] = 1, jump_num[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        dnum[i] = 1;
        jump_num[i] = i * jump_num[i - 1]; 
    }
    return ;
}


int get_num(int k, int n) {
    int ind = (k / jump_num[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int k, n;
    scanf("%d", &k);
    k -= 1;
    for (int i = max_n - 1; i >= 0; i--) {
        int num = get_num(k, i);
        printf("%d", num);
        k %= jump_num[i];
    }
    putchar('\n');
    return 0;
}
