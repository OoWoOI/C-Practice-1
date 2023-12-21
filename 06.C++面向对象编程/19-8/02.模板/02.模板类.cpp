/*************************************************************************
	> File Name: 02.模板类.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 07:09:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
class Array {
public:
    Array(int n):size(n) {
        this->arr = new T[n];
    }
    
    T &operator[](int ind) {
        if (ind < 0 || ind >= this->size) return this->end;
        return this->arr[ind];
    }
    
   template<typename U> 
    friend ostream &operator<<(ostream &, const Array<U> &);

    ~Array() {
        delete[] this->arr;
    }

private:
    T *arr;
    T end;
    int size;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    cout << "Class elem :";
    for (int i = 0; i < a.size; i++) {
        cout << " " << a.arr[i];
    }
    cout << endl;
    return out;
}


int main() {
    Array<int> a(10);
    Array<double> b(10);
    for (int i = 0; i < 10; i++) {
        a[i] = (rand() % 100);
        b[i] = (rand() % 100) / 100.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}
