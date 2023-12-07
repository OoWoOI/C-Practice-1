/*************************************************************************
	> File Name: 15.虚函数与纯虚函数_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 11:16:27 AM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;


string rand_name(int n) {
    string name = "";
    for (int i = 0; i < n; i++) {
        name += 'A' + rand() % 26;
    }
    return name;
}

class Animal{
public:
    Animal(){};
    Animal(string name):name(name){}
    string tell_me_name(){return this->name;}
    virtual void say() = 0;
    virtual void run() {
        cout << "I don't know how to run~~~" << endl;
    }
    virtual ~Animal(){
        cout << "Animal destructor~~~" << endl;
    }
private:
    string name;
};


class Cat : public Animal {
public:
    Cat():Animal(rand_name(5) + "_CAT"){}
    void say() override {
        cout << "my name is " << this->tell_me_name() << endl;
    }
    void run() override {
        cout << "I can run by four legs!" << endl;
    }
    ~Cat() {
        cout << "Cat destructor!" << endl;
    }
};

class Bat : public Animal {
public:
    Bat(): Animal (rand_name(5) + "_BAT"){}
    void say() override {
        cout << "My name is " << this->tell_me_name() << endl;
    }

    void run() override {
        cout << "I can fly !" << endl;
    }
    ~Bat(){
        cout << "Bat destructor!" << endl;
    }
    
};

//分割线
void ptline(string name, int n) {
    int size = name.length();
    n -= size;
    for (int i = n / 2; i >= 0; i--) {
        cout << "=";
    }
    cout << name;

    for (int i = n / 2; i >= 0; i--) {
        cout << "=";
    }
    cout << endl;
    return ;
}

int main() {
   ptline("测试1", 30); 
    Cat a;
    Bat b;
    cout << a.tell_me_name() << endl;
    a.run();
    cout << b.tell_me_name() << endl;
    b.run();
   ptline("测试2", 30);
    Animal ** arr = new Animal*[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
        arr[i]->say();
        arr[i]->run();
    }
    ptline("测试3", 30);
    for (int i = 0; i < 10; i++) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
