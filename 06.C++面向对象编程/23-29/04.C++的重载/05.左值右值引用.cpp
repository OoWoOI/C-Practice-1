/*************************************************************************
	> File Name: 05.左值右值引用.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 11:23:17 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define LEFT_OR_RIGHT(expr) { \
    printf("expr : %s\n", #expr); \
    left_or_right(expr); \
    printf("\n");  \
}

void left_or_right(int &, int);
void left_or_right(int &&, int);

void left_or_right(int &x, int flag = 1) {
    printf("left value : %d\n", x);
    if (flag) left_or_right(x, 0);
    return ;
}

void left_or_right(int &&x, int flag = 1) {
    printf("right value : %d\n", x);
    if (flag) left_or_right(forward<int &&>(x), 0);
    return ;
}

int main() {
    left_or_right(123);
    int a = 123;
    LEFT_OR_RIGHT(a);
    LEFT_OR_RIGHT(a + 1);
    LEFT_OR_RIGHT(123);
    LEFT_OR_RIGHT(a++);
    LEFT_OR_RIGHT(++a);
    LEFT_OR_RIGHT(a += 2);
    return 0;
}
