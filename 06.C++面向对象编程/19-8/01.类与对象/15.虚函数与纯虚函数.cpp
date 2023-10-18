/*************************************************************************
	> File Name: 15.虚函数与纯虚函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Oct 2023 10:17:25 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string rand_name(int n) {
    string name = "";
    for (int i = 0; i < n; i++) {
        name += (char)(rand() % 26 + 'A');
    }
    return name;
}


//父类:动物类
class Animal {
public:
    Animal() {}
    
    Animal(string name) : name(name){}
    
    string tell_me_your_name() { return this->name; }//普通成员方法
    
    virtual void run() {}//虚函数
    virtual void say() = 0;//纯虚函数
    //具有虚函数的类，析构函数应该使用virtual关键字修饰 
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }

private:
    string name;   
};


//子类：猫类
class Cat : public Animal {
public:
    Cat() : Animal(rand_name(5) + " Cat") {}//无参构造函数调用父类的有参构造函数
    
    void say() override {
        cout << "miao miao miao" << endl;
    }
    
    void run() override {
        cout << "I can run by four legs" << endl;
    }

    ~Cat() {
      cout << "Cat destructor" << endl;  
    }
};


//子类：蝙蝠类
class Bat : public Animal {
public:
    Bat() : Animal(rand_name(5) + " Bat") {}//无参构造函数调用父类的有参构造函数
    void say () override {
        cout << "zzz zzz zzz" << endl;
    }

    void run () override {
        cout << "I can fly" << endl;
    }
    
    ~Bat() {
        cout << "Bat destructor" << endl;
    }
};


int main() {
    Cat a;
    Bat b;
    cout << a.tell_me_your_name() << endl;
    a.run();
    cout << b.tell_me_your_name() << endl;
    b.run();
    cout << "=================" << endl;
    Animal **arr = new Animal*[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i]->tell_me_your_name() << endl;
        arr[i]->run();
        arr[i]->say();
        cout << "================" << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete arr[i];
        cout << "================" << endl;
    }

    delete[] arr;

    return 0;
}
