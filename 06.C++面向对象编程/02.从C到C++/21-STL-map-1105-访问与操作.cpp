/*************************************************************************
	> File Name: 21-STL-map-1105-访问与操作.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 03:12:45 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int main() {
    map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        auto x = mp.find(a);
        if (x == mp.end()) mp[a] = 1;
        else mp[a] += 1;
    }
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
