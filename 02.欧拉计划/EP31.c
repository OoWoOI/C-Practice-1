/*************************************************************************
	> File Name: EP31.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 07:19:50 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 8
#define max_m 200

int W[max_n] = {
    1, 2, 5, 10, 20, 50, 100, 200
};

int F[max_m + 5]; 

//递推式 : f(n, m) = f(n - 1, m) + f(n, m - W[n]);
//表示:求得前n种钱币的方法总数
int main() {
    F[0] = 1;
    for (int n = 0; n < max_n; n++) {
        for (int m = 1; m <= max_m; m++) {
            if (m >= W[n]) F[m] += F[m - W[n]];
        }
    }
    printf("%d\n", F[max_m]);
    return 0;
}


//方法1.递推 + 二维数组
/**
int W[max_n] = {
    1, 2, 5, 10, 20, 50, 100, 200
};

int F[max_n + 5][max_m + 5]; 

//递推式 : f(n, m) = f(n - 1, m) + f(n, m - W[n]);
//表示:求得前n种钱币的方法总数
int main() {
    for (int n = 0; n < max_n; n++) {
        F[n][0] = 1;
        for (int m = 1; m <= max_m; m++) {
            F[n][m] = 0;
            if (n >= 1) F[n][m] += F[n - 1][m];
            if (m >= W[n]) F[n][m] += F[n][m - W[n]];
        }    
    }
    printf("%d\n", F[(max_n - 1)][max_m]);
    return 0;
}*/



//方法2.递推 + 循环数组
/*
 
int W[max_n] = {
    1, 2, 5, 10, 20, 50, 100, 200
};

int F[2][max_m + 5]; 

//递推式 : f(n, m) = f(n - 1, m) + f(n, m - W[n]);
//表示:求得前n种钱币的方法总数
int main() {
    for (int k = 0; k < max_n; k++) {
        int n = k % 2;
        F[n][0] = 1;
        for (int m = 1; m <= max_m; m++) {
            F[n][m] = 0;
            F[n][m] += F[n ^ 1][m];
            if (m >= W[k]) F[n][m] += F[n][m - W[k]];
        }    
    }
    printf("%d\n", F[(max_n - 1) % 2][max_m]);
    return 0;
}
 */
