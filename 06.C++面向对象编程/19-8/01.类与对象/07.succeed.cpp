/*************************************************************************
	> File Name: 07.succeed.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Oct 2023 11:40:14 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    Animal(string name) : __name(name){}
    string name() {return this->__name;}
private :
    string __name;
};

class Cat : public Animal {
public : 
    Cat() : Animal("hello kitty") {}
    void say() {
        cout << "My name is " << this->name() << endl;
    }
private :

};

int main() {
    Cat c;
    c.say();  
    return 0;
}
