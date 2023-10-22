/*************************************************************************
	> File Name: 02.287.合并果子.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 09:33:55 PM CST
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
class Heap : public set<PII> {
public :
    Heap() : t(0) {}
    int top() { return begin()->first; }
    void push(int x)  {
        insert(PII(x, t++));
        return ;
    }
    void pop() {
        erase(begin());
        return ;
    }

private:
    int t;
};

int main() {
    Heap h;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        h.push(num);
    }
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int a = h.top(); h.pop();
        int b = a + h.top(); h.pop();
        h.push(b);
        sum += b;
    }
    
    cout << sum << endl;
    
    return 0;
}
