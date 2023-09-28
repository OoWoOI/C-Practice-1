/*************************************************************************
	> File Name: EP30.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 08:58:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>


//计算得出最大位数
int getMaxD() {
    int n = 1, flag = (int)pow(9, 5) * 5;
    while ((int)pow(10, n) < flag) {
        n++;
    }
    return n;
}

int is_val(int x) {
    int tmp = x, n = 0;
    while (tmp) {
        n += (int)pow(tmp % 10, 5);
        tmp /= 10;
    }
    return n == x;
}

int main() {
    int max = getMaxD(), sum = 0;
    for (int i = 2, I = (int)pow(10, max); i <= I; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
