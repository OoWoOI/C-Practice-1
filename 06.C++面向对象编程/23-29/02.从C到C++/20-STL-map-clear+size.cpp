/*************************************************************************
	> File Name: 20-STL-map-clear+size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 03:07:40 PM CST
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
    
    cout <<  mp.size() << " ";
    mp.clear();
    cout << mp.size() << endl;
    
    return 0;
}
