/*************************************************************************
	> File Name: EP19.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 08:11:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

int is_sunday(int d, int m, int y) {
    int ans = 0;
    ans = d + 2 * m;
    ans += 3 * (m + 1) / 5;
    ans += y;
    ans += (int)floor(y / 4) - (int)floor(y / 100);
    ans += (int)floor(y / 400);
    ans %= 7;
    printf("%d\n", ans);
    return ans == 6;
}

int main() {
    int cnt = 0;
    for (int y = 1901; y <= 2000; y++) {
        for (int m = 1; m <= 12; m++) {
            int md = m, yd = y;
            if (m == 1 || m == 2){
                md = m + 12;
                yd = y - 1;
            }
            cnt += is_sunday(1, md, yd);
            //printf("%d\n", cnt);
        } 
    }
    printf("%d\n", cnt);
    return 0;
}
