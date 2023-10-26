/*************************************************************************
	> File Name: 02.public_private.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:15:23 AM CST
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

class People {
public :
    void say() {
        cout << name << ", " << age << endl;
    }
    void set_name(string name) {
        this->name = name;
        return ;
    }
    void set_age(int age) {
        if (age <= 0) {
            perror("bushit, f*ck!");
            exit(1);
        }
        this->age = age;
        return ;
    }
private:
    string name;
    int age;
};

int main() {
    People hug;
    hug.set_name("Hug");
    hug.set_age(40);
    hug.say();
    return 0;
}
