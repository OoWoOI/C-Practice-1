/*************************************************************************
	> File Name: 13.STL-set-1091.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 12:59:12 PM CST
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
    s.clear();
    cout << s.size() << endl;
    return 0;
}
