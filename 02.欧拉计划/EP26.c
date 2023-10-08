/*************************************************************************
	> File Name: EP26.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 07:43:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_n 1000

int r_len[max_n + 5];

int get_len(int n) {
    memset(r_len, 0, sizeof(r_len));
    int r = 1, t = 1;
    r_len[1] = 1;
    while (r) {
        r *= 10;
        r %= n;
        t++;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, len = 0;
    for (int i = 2; i < max_n; i++) {
        int tmp = get_len(i);
        if (tmp > len) {
            d = i;
            len = tmp;
        }
    }

    printf("%d %d\n", d, len);
    return 0;
}
