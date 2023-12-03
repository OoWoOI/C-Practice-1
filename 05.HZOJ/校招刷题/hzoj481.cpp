/*************************************************************************
	> File Name: hzoj481.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 07:37:19 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int r, arr[15][2];

void print(int ind) {
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < ind; i++) {
        cout << arr[i][0] << ":" << arr[i][1] << endl;
        ans1 += arr[i][0];
        ans2 += arr[i][1];
    }
    cout << ans1 << ":" << ans2 << endl;
    return ;
}

int main() {
    cin >> r;

    for (int i = 0; i < 10; i++) {
        int num1[10] = {0}, num2[10] = {0};
        for (int j = 0; j < 8; j++) {
            cin >> num1[j];
            if (num1[j] == -1) {
                print(i);
                return 0;
            }
        }

        for (int j = 0; j < 8; j++) {
            cin >> num2[j];
        }
        
        sort(num1, num1 + 8);
        sort(num2, num2 + 8);
       
        if (num1[0]  < num2[0]) {
            for (int j = 0; j < 8; j++) {
                if (num1[j] > r || num1[j] >= num2[0]) {
                    break;
                }
                arr[i][0]++;
            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (num2[j] > r || num2[j] >= num1[0]) break;
                arr[i][1]++;
            }
        }

    }
    print(10);
    return 0;
}
