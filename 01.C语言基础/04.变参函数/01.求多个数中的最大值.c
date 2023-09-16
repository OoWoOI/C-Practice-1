/*************************************************************************
	> File Name: 01.求多个数中的最大值.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 12:00:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>

int max_n(int n, ...) {
    int ans = INT32_MIN;
    va_list args;
    va_start(args, n);
    while (n--) {
        int temp = va_arg(args, int);
        ans = ans > temp ? ans : temp;
    }
    va_end(args);
    return ans;
}

int main() {
    printf("max(%d) : %d\n", 3, max_n(3, 12, 15, 16));
    printf("max(%d) : %d\n", 4, max_n(4, 12, 12, 13, 17));
    return 0;
}
