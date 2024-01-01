/*************************************************************************
	> File Name: 01.auto关键字.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 04:18:00 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;
string randstring(int n) {
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += rand() % 26 + 'A';
    }
    return ret;
}

int my_seed = 1;
void my_srand(int seed) {
    my_seed = seed;
    return ;
}

int my_rand() {
    my_seed = my_seed * 3 % 101;
    return my_seed;
}

int main() {
    map<string, int> ind;
    for (int i = 0; i < 10; i++) {
        ind[randstring(rand() % 10 + 3)] = rand();
    }
    auto iter = ind.begin();
    for (; iter != ind.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    
    cout << "================" << endl;

    for (auto it : ind) {
        cout << it.first << " " << it.second << endl;
    }

    //自定义随机函数
    my_srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << my_rand() << endl;
    }
    return 0;
}
