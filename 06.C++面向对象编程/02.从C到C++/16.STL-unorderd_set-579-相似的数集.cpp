/*************************************************************************
	> File Name: 16.STL-unorderd_set-579-相似的数集.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 01:59:13 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_set>

using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_set<int> s[n];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            s[i].insert(num);
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int nc = 0, nt = s[a - 1].size();
        for (auto it = s[b - 1].begin(); it != s[b - 1].end(); it++) {
            auto x = s[a - 1].find(*it);
            if (x == s[a - 1].end()) nt++;
            else nc++;
        }
        printf("%.1lf%%\n", (nc * 1.0 / nt) * 100);
    }
    return 0;
}
