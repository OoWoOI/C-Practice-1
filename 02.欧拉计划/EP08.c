/*************************************************************************
	> File Name: EP08.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Sep 2023 10:07:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//欧拉计划第八题
//滑动窗法

int main() {
    
    int arr[1005], i = 0;
    char buff[1000] = {0}; 
    int n = 0;
    //读取数据
    while (~scanf("%s", buff)) {
        for (int i = 0; buff[i]; i++) {
          arr[n++]  = buff[i] - '0';
        }
        memset(buff, 0, sizeof(buff));
    }
    
    //处理数据
    long long ans = 0, k = 13, tmp = 1, zero_cnt = 0;
    //滑动窗口法
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            tmp *= arr[i]; 
        } else {
            zero_cnt++;
        }
        if (i < k) continue;

        if (arr[i - k] == 0) {
            zero_cnt--;
        } else {
            tmp /= arr[i - k];
        }
        
        if (!zero_cnt && ans < tmp) ans = tmp;

    }

    printf("result = %lld\n", ans);
    return 0;
}
