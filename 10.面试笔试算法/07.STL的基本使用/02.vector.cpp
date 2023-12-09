/*************************************************************************
	> File Name: 02.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 07:45:09 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
    
    //vector的基本使用
    
    /*
    vector<int > v(3, 5);
    v.push_back(6);
    v.push_back(7);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    */
   
    //验证vector的扩容原则

   /* 
    vector<int > v;
    int tmp = -1;
    for (int i = 0; i < 1000000; i++) {
        if (tmp != v.capacity()) {
            cout << v.capacity() << endl;
            tmp = v.capacity();
        }
        v.push_back(i);
    }
    */

    //定义二维数组
    vector<vector<int> > v(5, vector<int>(6, 2));
    cout << v[1][2] << endl;

    return 0;
}
