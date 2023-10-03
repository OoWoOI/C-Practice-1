/*************************************************************************
	> File Name: 10.STL-stack-570.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 10:55:54 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    int n, height, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> height;
        if (s.empty() || s.top() > height) {
            s.push(height);
            continue;
        }
        while (!s.empty() && s.top() < height) {
            s.pop();
            sum += s.size();
        }    
        s.push(height);
    }

    while (!s.empty()) {
            s.pop();
            sum += s.size();
    }
    cout << sum << endl;
    return 0;
}
