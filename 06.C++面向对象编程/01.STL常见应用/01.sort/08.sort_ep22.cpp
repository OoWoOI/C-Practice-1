/*************************************************************************
	> File Name: sort_ep22.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 06:57:00 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string name[6005];
int n, ans;

int main() {
    while (cin >> name[n]) {
        n++;
    }
    sort(name, name + n);
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < name[i].size(); j++) t += name[i][j] - 'A' + 1;
        ans += t * (i + 1);
    }
    cout << ans << endl;
    return 0;
    
}
