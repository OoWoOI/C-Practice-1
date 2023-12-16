/*************************************************************************
	> File Name: 02.hzoj235.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 08:15:27 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int n, num[15];

void print(int cnt) {
    for (int i = 1; i <= cnt; i++) {
       if (i != 1) printf(" ");
       printf("%d", num[i]);
    }
    printf("\n");
}

void func(int start, int ind) {
    for (int i = start; i <= n; i++) {
        num[ind] = i;
        print(ind);
        func(i + 1, ind + 1);
    }
    return ;
}

int main() {
    cin >> n;
    func(1, 1);
    return 0;
}
