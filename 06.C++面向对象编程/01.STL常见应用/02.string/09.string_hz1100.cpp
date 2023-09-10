/*************************************************************************
	> File Name: 09.string_hz1100.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 09:17:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string s1, s2, s3;
    int k, len;
    cin >> s1;
    cin >> k >> len;
    cin >> s2;
    s3 = s1.replace(k, len, s2);
    cout << s3 << endl;
    return 0;
}
