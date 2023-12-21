/*************************************************************************
	> File Name: 03.模板的特化与偏特化.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 07:33:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//类的特化与偏特化

template<typename T>
class Array {
public:
    Array(int n) : size(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if (ind < 0 || ind >= this->size) return this->__end;
        return this->arr[ind];
    }
    template<typename U> 
    friend ostream &operator<<(ostream &, const Array<U> &);
    ~Array() {
        delete[] this->arr;
    }
private:
    T *arr;
    T __end;
    int size;
};

template<>
class Array<double> {
public:
    Array(int n) : size(n) {
        cout << "类的特化: " << endl;
        this->arr = new double[n];
    }
    double &operator[](int ind) {
        if (ind < 0 || ind >= this->size) return this->__end;
        return this->arr[ind];
    }
    template<typename T> 
    friend ostream &operator<<(ostream &, const Array<T> &);
    ~Array() {
        delete[] this->arr;
    }
private:
    double *arr;
    double __end;
    int size;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    cout << "class template : " << sizeof(T) << endl;;
    for (int i = 0; i < a.size; i++) {
        cout << " " << a.arr[i];
    }
    return out;
}

//函数的特化与偏特化

template<typename T>
T add(T a, T b) {
    cout << "normal template function:" << endl;
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "special template function:" << endl;
    return a + b;
}

template<typename T> 
T add(T *a, T *b) {
    cout << "偏特化 function:" << endl; 
    return (*a) + (*b);
}


int main() {
    int a_num = 123, b_num = 234;
    cout << add(2, 3) << endl;
    cout << add(2.0, 3.0) << endl;
    cout << add(&a_num, &b_num) << endl;
    Array<int> a(10);
    Array<double> b(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
        b[i] = (rand() % 100) / 10.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}
