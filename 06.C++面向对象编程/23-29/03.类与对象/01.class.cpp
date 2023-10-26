/*************************************************************************
	> File Name: 01.class.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:12:46 AM CST
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
    string name;
    unsigned int age;
    char sex;
    
    void say() {
        cout << "My name is " << name;
        cout << ", I'm " << age << " years old, ";
        // sex : m, f
        if (sex == 'm') {
            cout << "I'm a boy!" << endl;
        } else {
            cout << "I'm a girl!" << endl;
        }
    }
};

int main() {
    People hug;
    hug.name = "Captain Hu";
    hug.age = 40;
    hug.sex = 'm';
    hug.say();
    return 0;
}


