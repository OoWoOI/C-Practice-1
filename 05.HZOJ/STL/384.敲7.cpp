/*************************************************************************
	> File Name: 384.敲7.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 10:41:41 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct node {
    int t;
    int flag;
} Node;

int isVal(int x) {
    while (x) {
        if ((x % 10) == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int N, X, T;
    cin >> N >> X >> T;
    Node node[N + 5] = {0};
    for (int i = 0; i < N; i++) node[i] = {i + 1, 0};
    int size = N;
    while (size > 1) {
        //cout << X % N << endl;
        if (node[(X - 1) % N].flag) {
            X++;
            continue;
        }
        if (T % 7 == 0 || isVal(T)) {
            node[(X - 1) % N].flag = 1;
            //cout << node[(X - 1) % N].t << endl;
            size--;
        }
        X++;
        T++;
    }
    for (int i = 0; i < N; i++) node[i].flag == 0 && printf("%d\n", node[i].t);
    return 0;
}
