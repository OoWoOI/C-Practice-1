/*************************************************************************
	> File Name: 02.hzoj381.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 08:59:09 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct student{
    string name;
    int cla, avg, paper, num, sum;
    char off, west;
};

bool cmp(const student &a, const student &b) {
    if (a.sum == b.sum) return a.num < b.num;
    return a.sum > b.sum;
}

student stu[1005];
int n, ans;

int func(student &a) {
    a.sum = 0;
    if (a.avg > 80 && a.paper >= 1) a.sum += 8000;
    if (a.avg > 85 && a.cla > 80) a.sum += 4000;
    if (a.avg > 90) a.sum += 2000;
    if (a.avg > 85 && a.west == 'Y') a.sum += 1000;
    if (a.cla > 80 && a.off == 'Y') a.sum += 850;
    return a.sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].off >> stu[i].west >> stu[i].paper;
        stu[i].num = i;
        ans += func(stu[i]);
    }
    
    sort(stu, stu + n, cmp);

    cout << stu[0].name << endl << stu[0].sum << endl << ans << endl;
    
    return 0;
}
