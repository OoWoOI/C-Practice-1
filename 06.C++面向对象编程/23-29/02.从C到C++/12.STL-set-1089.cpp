/*************************************************************************
	> File Name: 12.STL-set-1089.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 12:48:49 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    
    auto it = s.find(x);
    if (it != s.end()) s.erase(it);
    for (auto sit = s.begin(); sit != s.end(); sit++) {
        sit != s.begin() && cout << " ";
        cout << *sit;
    }
    cout << endl;
    return 0;
}
