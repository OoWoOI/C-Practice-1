/*************************************************************************
	> File Name: 05.euler-22.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 07:30:59 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
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
        for (int j = 0; j < name[i].size(); j++) {
            t += name[i][j] - 'A' + 1;
        }
        ans += t * (i + 1);
    }

    cout << ans << endl;
    
    return 0;
}
