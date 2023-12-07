/*************************************************************************
	> File Name: hzoj519_优雅数.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 09:08:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long a, b, ans;
int main() {
    cin >> a >> b;
    //特殊数
    for (int i = 0; i < 10; i++) {
        //一般数
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            //长度
            for (int k = 3; k <= 17; k++) {
                //位置
                for (int l = 1; l <= k; l++) {
                    if (i == 0 && l == 1) continue;
                    if (j == 0 && l != 1) break;
                    long long t = 0;
                    //构造优雅数
                    for (int m = 1; m <= k; m++) {
                        if (m == l) {
                            t = t * 10 + i;
                        } else {
                            t = t * 10 + j;
                        }
                    }
                    
                    if (a <= t && t <= b) {
                        ans++;
                    }
                }
            }

        }
    }
    cout << ans << endl;
    return 0;
}
