/*************************************************************************
	> File Name: 01.function_ovrload.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 12:27:34 PM CST
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

void output(int x) {
    printf("output int : %d\n", x);
    return ;
}

void output(long long x) {
    printf("output long long : %llX\n", x);
    return ;
}

void output(const char *s) {
    if (!s) {
        printf("output string : nullptr\n");
    } else {
        printf("output string : %s\n", s);
    }
    return ;
}

void output(int x, int y) {
    printf("output double int : %d, %d\n", x, y);
    return ;
}

const char *output(int a, int b, int c) {
    printf("output three int : a = %d, b = %d, c = %d\n", a, b, c);
    return "output function";
}

void f(int a = 1, int b = 2, int c = 3) {
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return ;
}

int main() {
    output(3, 4); // int, int
    output(3LL, 4);
    output(3); // int
    output(3LL); // long long
    output("hello world");
    output(nullptr);
    f();
    f(12);
    f(12, 13);
    f(12, 13, 14);
    cout << output(3, 4, 2) << endl;
    return 0;
}

