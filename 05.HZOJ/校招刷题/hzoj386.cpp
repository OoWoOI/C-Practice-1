/*************************************************************************
	> File Name: hzoj386.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 07:29:02 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 100000
int M, N;
long long val;

struct Node{
    long long val;
    int indx;
};

Node num[MAX_N + 5];

int bs() {
    int l = 1, r = M, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (num[mid].val == val) return num[mid].indx;
        if (num[mid].val < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= M; i++) {
        scanf("%lld", &num[i].val);
        num[i].indx = i;
    }
    sort(num + 1, num + M + 1, [](const Node &a, const Node &b){
        return a.val < b.val;
    });
    for (int i = 0; i < N; i++) {
        scanf("%lld", &val);
        int ind = bs();
        printf("%d\n", (ind == -1 ? 0 : ind));
    }
    return 0;
}
