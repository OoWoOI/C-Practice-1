/*************************************************************************
	> File Name: 04.变参模板.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:28:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//1.变参模板   函数  ===> 递归展开
template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

/**
//2.变参模板 类 ===> 递归展开

template<typename T, typename ...ARGS> 
struct ARG {
    typedef T getT;
    typedef ARG<ARGS...> rest;
};

template<typename T>
struct ARG<T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T> class Test;

template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    T operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::finalT b) {
        return a + b;
    } 
};

**/

//3.变参模板类展开 ===> 递归

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG< 0, T, ARGS...> {
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    } 
};

int main() {
    //1
    print(2.3, 4, 3, "hello word!"); 
    /**
    //2
    cout << sizeof(ARG<int, float, double>::getT) << endl;
    cout << sizeof(ARG<int, float, double>::rest::getT) << endl;
    cout << sizeof(ARG<int, float, double>::rest::rest::getT) << endl;
    ARG<int, float, double>::getT a = 123;
    ARG<int, float, double>::rest::getT b = 123.00;
    ARG<int, float, double>::rest::rest::getT c = 123.45;
    cout << a << " " << b << " " << c << " " << endl; 
    Test<int(float, double)> d;
//    Test<int(double, float, int, int)> e;
    cout << d(2.3, 4.5) << endl;
    **/
    
    Test<int(double, float)> d;
    cout << d(2.3, 4.5) << endl;
    return 0;
}
