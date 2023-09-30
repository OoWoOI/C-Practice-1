/*************************************************************************
	> File Name: EP11.c
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Sep 2023 07:25:04 PM CST
 ************************************************************************/

#include<stdio.h>

#define max_n 20

int nums[25][25];

int k[4][2] = {
    {-1, -1}, {-1, 0},
    {-1, 1}, {0, 1}
};

int calc(int x, int y) {
    int ans = 0;
    
    for (int i = 0; i < 4; i++) {
        //四个方向
        int tmp = 1;
        for(int step = 0; step < 4; step++) {
            //走四步
            int dx = x + k[i][0] * step;
            int dy = y + k[i][1] * step;
            if (dx < 0 || dx >= max_n) break;
            if (dy < 0 || dy >= max_n) break;
            tmp *= nums[dx][dy];
        }
        if (tmp > ans) ans = tmp;
    }
    return ans;
}

//初始化数组
void init() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    return ;
}

int main() {
    init();
    int ans = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
           int tmp = calc(i, j);
            if (ans < tmp) ans = tmp;
        }
    }
    printf("%d\n", ans);
    return 0;
}
