/*************************************************************************
	> File Name: hzoj569.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 09:04:06 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int n;
double v0, c0, salt0;
struct node {
    double v, c, salt;
};
int main() {
    stack<node> sta;

    cin >> v0 >> c0;
    salt0 = v0 * c0 / 100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char C;
        cin >> C;
        if (C == 'P') {
            double vt, ct, saltt;
            cin >> vt >> ct;
            saltt = vt * ct / 100;
            v0 += vt;
            salt0 += saltt;
            sta.push((node){vt, ct, saltt});
        } else {
            if (!sta.empty()) {
                v0 -= sta.top().v;
                salt0 -= sta.top().salt;
                sta.pop();
            }
        }
        printf("%d %.5lf\n", (int)v0, salt0 / v0 * 100);
    }
    
    return 0;
}
