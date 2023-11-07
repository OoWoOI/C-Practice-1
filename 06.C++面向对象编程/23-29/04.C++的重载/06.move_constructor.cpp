/*************************************************************************
	> File Name: 06.move_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 11:24:07 AM CST
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
#include<cassert>
using namespace std;

class Array {
public :
    Array(int n) : n(n), arr(new int[n]) {
        cout << "default constructor : " << arr << endl;
    }
    Array(const Array &a) : n(a.n), arr(new int[n]) {
        cout << "copy constructor : " << arr << endl;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
        return ;
    }
    Array(Array &&a) : n(a.n), arr(a.arr) {
        cout << "move constructor : " << arr << endl;
        a.arr = nullptr;
        a.n = 0;
        return ;
    }
    void output(const char *frm) {
        for (int i = 0; i < n; i++) {
            printf(frm, i, arr[i]);
        }
        printf("\n");
        return ;
    }
    int &operator[](int ind) const {
        assert(ind >= 0 && ind < n);
        return arr[ind];
    }
    ~Array() {
        cout << "Array destructor : " << arr << endl;
        if (arr == nullptr) return ;
        delete[] arr;
        return ;
    }

private:
    int n;
    int *arr;
};

Array func() {
    int n = 7;
    Array a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    return a;
}

int main() {
    int n = 5;
    Array a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    a.output("a[%d]=%d, ");
    Array b = func();
    b.output("b[%d]=%d, ");
    Array c(move(a));
    c.output("c[%d]=%d, ");
    return 0;
}
