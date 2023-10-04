/*************************************************************************
	> File Name: EP15.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2023 09:10:50 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    long m = 40, n = 20, ans = 1;
    while (m != 20 || n != 0) {
        if (m != 20) ans *= (m--);
        if (n != 0 && ans % n == 0) ans /= (n--);
    } 
    printf("%ld\n", ans);
    return 0;
}
