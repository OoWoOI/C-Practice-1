/*************************************************************************
	> File Name: 11.STL-set-1088.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 11:47:21 AM CST
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    //1.迭代器
    for (set<int>:: iterator it = s.begin(); it != s.end(); it++) {
       if(it != s.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;

    //2.auto
    for (auto it = s.begin(); it != s.end(); it++) {
        it != s.begin() && cout << " ";
        cout << *it;
    } 
    cout << endl;

    //3.range base
    int flag = 0;
    for (int it : s) {
        flag && cout << " ";
        cout << it;
        flag++;
    }
    cout << endl;

    return 0;
}
