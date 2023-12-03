/*************************************************************************
	> File Name: hzoj480.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 09:07:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct node{
    char s[4];
    int num1, num2, flag;//flag取值就0代表不加分、1代表加下一球的分、2代表加下两球的分
};

int n, ans;
node bl[15];

int main() {
    
    //预处理信息
    while (cin >> bl[n].s) {
        if (bl[n].s[0] == '/') {
            bl[n].num1 = 10;
            bl[n].num2 = 10;
            bl[n].flag = 2;//再加两球
        } else if (bl[n].s[1] == '/') {
            bl[n].num1 = bl[n].s[0] - '0';
            bl[n].num2 = 10;
            bl[n].flag = 1;//再加一球的分数
        } else {
            bl[n].num1 = bl[n].s[0] - '0';
            bl[n].num2 = bl[n].num1 + (bl[n].s[1] - '0');
            bl[n].flag = 0;
        }
        n++;
    } 

    //统计分数
    
    for (int i = 0; i < 10; i++) {
        ans += bl[i].num2;
        if (bl[i].flag == 1) {
            ans += bl[i + 1].num1;

        } else if (bl[i].flag == 2) {
            if (bl[i + 1].flag == 2) {
                ans += 10 + bl[i + 2].num1;
            } else {
                ans += bl[i + 1].num2;
            }
        }        
    }

    cout << ans << endl;
    return 0;
}
