/*************************************************************************
	> File Name: 04.transfer_costructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Oct 2023 10:34:51 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//类型转换构造函数

class BigInt {
public:
    BigInt(){}
    BigInt(int x) {
         //将一个整型数组转换为大整数
        num.push_back(x);
        proccess_digits();
    }
    friend ostream &operator<<(ostream &, const BigInt &); 
private:
    vector<int> num;
    void proccess_digits() {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

void func(BigInt a) {
    cout << "func :" << a << endl;
    return ;
}

int main() {
    BigInt a(123);
    cout << a << endl;
    func(4567);
    return 0;
}
