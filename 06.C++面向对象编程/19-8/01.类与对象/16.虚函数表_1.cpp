/*************************************************************************
	> File Name: 16.虚函数表_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 11:53:46 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string rand_name(int n) {
    string name = "";
    for (int  i = 0; i < n; i++) {
        name += 'A' + rand() % 26;
    }
    return name;
}

class Animal{
public:
    Animal(string name): name(name) {}
    string tell_me_name() {return this->name;}
    virtual void say(int x) = 0;
    virtual void run() = 0;
    virtual ~Animal() {
        cout << "Animal destructor!" << endl;
    }
private:
    string name;
};


class Cat : public Animal {
public:
    Cat():Animal(rand_name(5) + "_Cat") {}
    void say(int x) override {
        cout << this << endl;
        cout << x << endl;
        cout <<"I'm Cat, My name is " << this->tell_me_name() << endl;
        return ;
    }
    void run() override {
        cout << "I can run by four legs!"<< endl;
        return ;
    }
    ~Cat() {
        cout << "Cat destructor!" << endl;
    }
};


void out_raw_data(void *q, int n) {
    printf("%p : ", q);
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < n; i++) {
        printf("%2x ", p[i]);
    }
    printf("\n");
    return ;
}

typedef void (*func)(void *, int x);

int main() {
    Cat a, b;
    out_raw_data(&a, sizeof(a));
    out_raw_data(&b, sizeof(b));
    ((func **)(&a))[0][0](&a, 123);
    return 0;
}
