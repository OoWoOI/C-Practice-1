/*************************************************************************
	> File Name: 03.hzoj236.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 08:37:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, num[15];

void print() {
    for (int i = 1; i <= m; i++) {
        if (i != 1) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return ;
}
 
void func(int start, int ind, int left) {
    if (left == 0) {
        print();
        return ;
    }
    
    for (int i = start; i <= n; i++) {
        num[ind] = i;
        func(i + 1, ind + 1, left - 1);
    }
 
    return ;
}

int main() {
    
   cin >> n >> m;
    func(1, 1, m);
    return 0;
}
