/*************************************************************************
	> File Name: 14.IntArr-练习.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 11:04:18 AM CST
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;

class IntArray {
    

};


int main() {
   srand(time(0));
    IntArray a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    cout << a[4] << endl;
    cout << a[-2] << endl; // 输出倒数第 2 位的值
    cout << a << endl; // 输出整个数组中的元素
    a += 5; // 给数组中所有元素都加5
    cout << a << endl; // 输出整个数组中的元素
    cout << (a++) << endl; // 给数组中的所有元素都加 1
    cout << (++a) << endl; // 给数组中的所有元素都加 1
    return 0;
}
