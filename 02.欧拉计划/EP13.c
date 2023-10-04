/*************************************************************************
	> File Name: EP13.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2023 08:40:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define max 100

char ans[max + 5];

int main() {
    ans[0] = 1;
    for (int i = 0; i < max; i++) {
        char buff[max + 5]= {0};
        scanf("%s", buff);
        printf("%s\n", buff);
        int size = strlen(buff);
        for (int j = 0; buff[j]; j++) {
            ans[j + 1] += (buff[size - j - 1] - '0');
        }

        ans[0] = (ans[0] > size) ? ans[0] : size;
        
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    for (int i = ans[0]; i >= ans[0] - 9; i--) printf("%d", ans[i]);
    putchar('\n');
    return 0;
}
