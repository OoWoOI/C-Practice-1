/*************************************************************************
	> File Name: 07.sort_hz380.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 05:34:24 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct animals {
    int id;
    string votes;//票数
};

bool cmp(const animals &a, const animals &b) {
    if (a.votes.length() == b.votes.length()) return a.votes > b.votes;
    return a.votes.length() > b.votes.length();
}

int main() {
    int n;
    cin >> n;
    animals anim[105];
    //输入
    for (int i = 0; i < n; i++) {
        cin >> anim[i].votes;
        anim[i].id = i + 1;
    }
    
    //排序
    sort(anim, anim + n, cmp);
    //输出
    cout << anim[0].id << endl;
    cout << anim[0].votes << endl;
    return 0;
}
