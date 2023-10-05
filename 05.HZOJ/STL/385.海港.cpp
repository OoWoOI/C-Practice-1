/*************************************************************************
	> File Name: 385.海港.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 11:36:39 AM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

typedef struct boats {
    int time;//到达时间
    int *cnt; //国家种类
}boats;

int main() {
    int n;
    cin >> n;
    boats *bt = (boats *)calloc(sizeof(boats), n);
    
    for (int i = 0; i < n; i++) {
        cin >> bt[i].time;//到达时间    
        int k;
        cin >> k;//乘客总人数
        bt[i].cnt = (int *)calloc(sizeof(int), k);
        for (int j = 0; i < k; j++) cin >> bt[i].cnt[j];//乘客国籍
    }

    //统计情况
    for (int i = 0; i < n; i++) {
        
    }
    return 0;
}
