/*************************************************************************
	> File Name: hzoj516_奶牛碑文.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 07:59:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int n;
char str[MAX_N + 5];
long long numC[MAX_N + 5], numW[MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (str[i] == 'C') numC[i] = i - 1 >= 0 ? numC[i - 1] + 1 : 1;
        else numC[i] = i - 1 >= 0 ? numC[i - 1] : 0;
        
        if (str[j] == 'W') numW[j] = j + 1 < n ? numW[j + 1] + 1 : 1;
        else numW[j] = j + 1 < n ? numW[j + 1] : 0;
    }
    
    long long cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'O') cnt += (numC[i] * numW[i]);
    }

    cout << cnt << endl;
    return 0;
}
