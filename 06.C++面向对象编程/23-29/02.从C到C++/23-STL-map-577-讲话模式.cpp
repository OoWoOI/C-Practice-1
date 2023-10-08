/*************************************************************************
	> File Name: 23-STL-map-577-讲话模式.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 03:52:30 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<cctype>

using namespace std;
int main() {
    string str, ans;
    map<string, int> mp;
    int ans_cnt = 0;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
        mp[str] = mp[str] + 1;
        int t = mp[str];
        if (t > ans_cnt) {
            ans_cnt = t;
            ans = str;
        }

        if (t == ans_cnt) {
            ans = min(ans, str);
        }
    }    

    cout << ans << " " << ans_cnt << endl;
    
    return 0;
}
