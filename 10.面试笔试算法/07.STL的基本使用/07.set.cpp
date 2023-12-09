/*************************************************************************
	> File Name: 07.set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 09:18:34 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;

struct node{
    int x, y;
    bool operator<(const node &b) const {
        return this->x > b.x;
    }
};

int main() {
    set<node> s;
    s.insert((node){2, 3});
    s.insert((node){4, 5});
    s.insert((node){6, 7});

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->x << " " << it->y << endl; 
    }



    /*
    set<int> s;
    s.insert(8);
    s.insert(99);
    s.insert(5);
    s.insert(-2);
    s.insert(22);
    s.insert(5);
    s.insert(8);
    s.insert(5);

    cout << s.size() << endl;

    if (s.count(5) == 1) {
        cout << "5 yes" << endl;
    } else {
        cout << "5 not" << endl;
    }

    s.erase(5);

    if (s.count(5) == 1) {
        cout << "5 yes" << endl;
    } else {
        cout << "5 no" << endl;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    */
    return 0;
}
