/*************************************************************************
	> File Name: EP23.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 09:25:47 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 28123
#define MAX_M 30000

int prime[MAX_M + 5];
int f[MAX_M + 5];
int cnt[MAX_M + 5];
int d[MAX_M + 5];

void init() {
    
    for (int i = 2; i <= MAX_M; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }

        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_M; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }

        }
    
    }
}

int nums[MAX_M + 5] = {0};

int main() {
    init();
    
    //因子和
    for (int i = 1; i <= MAX_M; i++) {
        int sum = 0;
        int cnt = f[i];
        for (int j = 1; j < i && cnt; j++) {
            if (i % j) continue;
            sum += j;
            cnt--;
        }
       // printf("%d %d\n", i, sum);
        d[i] = sum;
    }
     
    long long sum = 0;
    //筛选所有的盈数
    for (int i = 1; i < MAX_N; i++) {
        if (d[i] <= i) continue;
        nums[++nums[0]] = i;
        for (int j = 1; j <= nums[0] && i + nums[j] < MAX_N; j++) {
            if (d[i + nums[j]] == 0) continue;
            if ( (i + nums[j]) < d[nums[j] + i]) continue;
            printf("ans = %d %d\n", nums[j] + i, d[nums[j] + i]);
            sum += i + nums[j];
            d[i + nums[j]] = 0;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
