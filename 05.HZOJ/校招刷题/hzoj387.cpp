/*************************************************************************
	> File Name: hzoj387.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 07:50:22 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//变量声明与定义
#define MAX_N 100000

struct Node{
    long long val;
    int indx;
};

int M, N;
long long val;

Node num[MAX_N + 5];

//查找函数
int bs() {
    int l = 1, r = M, mid;
    while (l != r) {
        mid = (l + r) >> 1;
        if (num[mid].val < val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    return num[r].val >= val ? num[r].indx : 0;
}

int main() {
    //输入数据规模
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= M; i++) {
        scanf("%lld", &num[i].val);
        num[i].indx = i;
    }
    //排序
    sort(num + 1, num + M + 1, [](const Node &a, const Node &b){
        return a.val < b.val;
    });
    //检索结果
    for (int i = 0; i < N; i++) {
        scanf("%lld", &val);
        int ind = bs();
        printf("%d\n", ind);
    }

    return 0;
}
