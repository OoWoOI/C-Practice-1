/*************************************************************************
	> File Name: 04.hzoj237.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 08:51:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, cnt = 1, num[15], mark[15];
    

void print() {
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return ;
}

void func() {
    if (cnt == n + 1) {
        print();
        return ;
    }

    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            num[cnt] = i;
            cnt++;
            func();
            cnt--;
            mark[i] = 0;
        }
    }
    
    return ;
}

int main() {
    cin >> n;
    func();
    return 0;
}
