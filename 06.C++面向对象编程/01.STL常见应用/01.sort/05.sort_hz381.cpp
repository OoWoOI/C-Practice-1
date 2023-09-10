/*************************************************************************
	> File Name: 05.sort_hz381.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 04:07:22 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct student {
    string name;
    int ind;
    int averageScore;
    int score;
    char leader;
    char west;
    int paper;
    int money = 0;
};

bool cmp(const student &a, const student &b) {
    if (a.money == b.money) return a.ind < b.ind;
    return a.money > b.money;
}


int main() {
    //输入数据
    int n;
    cin >> n;
    student stu[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].averageScore >> stu[i].score >> stu[i].leader >> stu[i].west >> stu[i].paper;
        stu[i].ind = i;
        if (stu[i].averageScore > 80 && stu[i].paper > 0) stu[i].money += 8000;
        if (stu[i].averageScore > 85 && stu[i].score > 80) stu[i].money += 4000;
        if (stu[i].averageScore > 90) stu[i].money += 2000;
        if (stu[i].averageScore > 85 && stu[i].west == 'Y') stu[i].money += 1000;
        if (stu[i].score > 80 && stu[i].leader == 'Y') stu[i].money += 850;
        sum += stu[i].money;
    }

    //排序
    sort(stu, stu + n, cmp);
    //输出
    cout << stu[0].name << endl;
    cout << stu[0].money << endl;
    cout << sum << endl;
    return 0;
}
