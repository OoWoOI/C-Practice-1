/*************************************************************************
	> File Name: 04.class.move_construct.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 09:51:44 AM CST
 ************************************************************************/

#include<iostream>
#include<assert.h>
using namespace std;

class Array {
public:
    Array(int n) : n(n), arr(new int[n]) {}
   
    Array(const Array &a) : n(a.n), arr(new int[n]) {
        cout << "copy constructor : " << arr <<  endl;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
        return ;
    }
    
    Array(Array &&a) : n(a.n), arr(a.arr) {
        cout << "move copy constructor" << endl;
        a.arr = nullptr;
        return;
    }

    void output(const char *frm) {
        for (int i = 0; i < n; i++) {
            printf(frm, i, arr[i]);
        }
        printf("\n");
        return ;
    }
    
    int &operator[](int ind) const{
        assert(ind >= 0 && ind < n);
        return arr[ind];
    }

    ~Array() {
        cout << "Array destructor" << arr << endl;
        if (arr == nullptr) return;
        delete[] arr;
        return ;
    }
private:
    int n;
    int *arr;
};

Array func() {
    Array a(7);
    for (int i = 0; i < 7; i++) {
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
    
    a.output("a[%d] = %d,");
    Array b(a);
    a.output("a[%d] = %d,");
    b.output("b[%d] = %d,");
    Array c = func();
    c.output("c[%d] = %d,");
    Array d(move(a));
    d.output("d[%d] = %d, ");
    
    return 0;
}
