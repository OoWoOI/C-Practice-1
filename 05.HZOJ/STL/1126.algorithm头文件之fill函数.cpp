/*************************************************************************
	> File Name: 1126.algorithm头文件之fill函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 04:52:56 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int a[100];
    int n, k;
    cin >> n >> k;

    fill(a, a + n, k);
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
