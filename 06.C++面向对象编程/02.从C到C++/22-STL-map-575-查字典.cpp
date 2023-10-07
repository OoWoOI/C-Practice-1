/*************************************************************************
	> File Name: STL-map-575-查字典.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 03:27:30 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int main() {
    map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str; int num;
        cin >> str >> num;
        mp[str] = num;
    }
    
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string str;
        cin >> str;
        cout <<mp[str]<< endl;
    }

    return 0;
}
