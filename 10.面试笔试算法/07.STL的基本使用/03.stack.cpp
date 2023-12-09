/*************************************************************************
	> File Name: 03.stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 08:01:01 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> sta;
    sta.push(99);
    sta.push(12);
    sta.push(11);
    sta.push(13);

    while (!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }
    return 0;
}
