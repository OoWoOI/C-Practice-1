/*************************************************************************
	> File Name: 17.自定义哈希函数哈希表_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 12:44:21 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

//自定义结点类
class Node {
public :
    Node() : flag(false), str(nullptr) {}

    void clear() {
        this->flag = false;
        if (this->str) free(this->str);
        this->str = nullptr;
        return ;
    }
    
    void insert(const char *str) {
        this->clear();
        this->flag = true;
        this->str = strdup(str);
        return ;
    }

    bool empty() {
        return this->flag == false;
    }

    ~Node() {
        if (this->str) free(this->str);
        this->str = nullptr;
    }

private :
    bool flag;
    char *str;
};

//哈希函数抽象类
class HashFunc {
public :
    virtual int operator()(const char *str) const = 0;
};

class HashTable {
public :
    typedef function<int(const char *)> HashFuncT;
    HashTable(HashFuncT func);
    bool insert(const char *str);
    bool find(const char *str);
    ~HashTable();

private :
    Node  &find_position(const char *);
    int _size;
    Node *data;
    HashFuncT p_Func;
};

int main() {
    
    return 0;
}
