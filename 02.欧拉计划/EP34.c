/*************************************************************************
	> File Name: EP34.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 09:27:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
//欧拉计划34题

//初始化阶乘数组
int nums[10];

void init_nums() {
    nums[1] = 1, nums[0] = 1;
    int i = 1;
    while (i <= 9) nums[i] = i * nums[i - 1], i++;
    return ;
}


int tenPow(int n) {
    return (int)pow(10, n);
}

int NineDF(int n) {
    int num = nums[9];
    return n * num;
}

int getMaxD() {
    int n = 1;
    while (tenPow(n) < NineDF(n)) n++;
    return n;
}

int is_val(int num) {
    int tmp = num, ans = 0; 
    while (tmp) {
        ans += nums[tmp % 10];
        tmp /= 10;
    }
    return ans == num;
}

int main() {
    init_nums();//初始化数组
    int max = getMaxD(), sum = 0;
    for (int i = 3, I = NineDF(max); i <= I; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
