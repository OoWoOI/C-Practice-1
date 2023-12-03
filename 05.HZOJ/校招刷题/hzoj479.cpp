/*************************************************************************
	> File Name: hzoj479.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 08:18:07 PM CST
 ************************************************************************/

#include<iostream>

using namespace std;

int ans11[5005][2], ans21[5005][2], cnt11, cnt21;

void print() {
    for (int i = 0; i <= cnt11; i++) {
        cout << ans11[i][0]  << ":" << ans11[i][1] << endl;
    }
    cout << endl;

    for (int i = 0; i <= cnt21; i++) {
        cout << ans21[i][0] << ":" << ans21[i][1] << endl;
    }
}

int main() {
    char s[35];
    while (cin >> s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'E') {
                print();
                return 0;
            }
            //统计得分情况
            if (s[i] == 'W') {
                ans11[cnt11][0]++;
                ans21[cnt21][0]++;
            } else {
                ans11[cnt11][1]++;
                ans21[cnt21][1]++;
            }
            //统计单局输赢在不同分制下的情况
            
            if ((ans11[cnt11][0] >= 11 || ans11[cnt11][1] >= 11) && (abs(ans11[cnt11][0] - ans11[cnt11][1]) >= 2)) {
                cnt11++;
            }

            if ((ans21[cnt21][0] >= 21 || ans21[cnt21][1] >= 21) && (abs(ans21[cnt21][0] - ans21[cnt21][1]) >= 2) ) {
                cnt21++;
            }
        }
    }
    
    return 0;
}
