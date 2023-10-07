/*************************************************************************
	> File Name: 18.STL-map-1102-find.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 02:56:35 PM CST
 ************************************************************************/

#include<iostream>
#include<map>

using namespace std;
int main() {
    int n;
    cin >> n;
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a >> b;
        mp[a] = b;
    }
    char k;
    cin >> k; 
    auto x = mp.find(k);
    if (x == mp.end()) cout << -1 << endl;
    else cout << mp[k] << endl;

    return 0;
}
