/*************************************************************************
	> File Name: 14.STL-set-修改排序规则.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 01:06:44 PM CST
 ************************************************************************/

#include<iostream>
#include<set>

using namespace std;
struct node {
    int x, y;
    bool operator<(const node &a) const {
        return this->x > a.x;//x 大 -> 小
    }
};

int main() {
    set<node> s;
    s.insert((node){2, 8});
    s.insert((node){1, 10});
    s.insert((node){5, 9});
    s.insert((node){0, 2});
    s.insert((node){4, 3});
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->x << " " << it->y << endl;
    }

    return 0;
}
