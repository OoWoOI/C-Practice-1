/*************************************************************************
	> File Name: 17.STL-map-1101-赋值与遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 02:45:53 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int main() {
    map<char, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a >> b;
        mp[a] = b;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
