/*************************************************************************
	> File Name: 19.STL-map-1103-erase.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 03:02:59 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int main() {
    map<char, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a; int b;
        cin >> a >> b;
        mp[a] = b;
    }
    char k;
    cin >> k;
    mp.erase(k);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
