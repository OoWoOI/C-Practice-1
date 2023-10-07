/*************************************************************************
	> File Name: 15.STL-set-453-第k小元素.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 01:25:45 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    if (k > s.size()) {
        cout << "NO RESULT" << endl;
        return 0;
    }
    auto it = s.begin();
    advance(it, k - 1);//前 ->, 后 <-;
    cout << *it << endl;
    return 0;
}
