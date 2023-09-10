/*************************************************************************
	> File Name: 06.sort_hz375.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 05:06:44 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct Student {
    int id;
    int chineses;
    int math;
    int eglish;
    int total;
};

bool cmp(const Student &a, const Student &b) {
    if (a.total == b.total && a.chineses != b.chineses) return a.chineses > b.chineses;
    if (a.total == b.total && a.chineses == b.chineses) return a.id < b.id;
    return a.total > b.total;
}

int main() {
    int n;
    cin >>  n;
    Student stu[n];
    //输入数据
    for (int i = 0; i < n; i++) {
        cin >> stu[i].chineses >> stu[i].math >> stu[i].eglish;
        stu[i].id = i + 1;
        stu[i].total = stu[i].chineses + stu[i].math + stu[i].eglish;
    }
    //排序
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu[i].id << " "<< stu[i].total << endl;
    }
    return 0;
}
