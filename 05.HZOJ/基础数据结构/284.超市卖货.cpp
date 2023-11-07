/*************************************************************************
	> File Name: 284.超市卖货.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 07:23:16 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//商品类
class Goods{
public:
    Goods(){}
    Goods(int d, int p):d(d), p(p) {}
    Goods(const Goods &a):d(a.d), p(a.p){}
    ~Goods(){}
    
    int d;
    int p;
};


int main() {
    int n;
    cin >> n;

    vector<Goods > gds(n);
    
    for (int i = 0; i < n; i++) {
        cin >> gds[i].p >> gds[i].d;
    }
    
    sort(gds.begin(), gds.end(), [](Goods &a, Goods &b){
            return a.d < b.d;
    });
    
    //优先队列
    auto cmp = [](int a, int b){
        return (a) < (b);
    };
    priority_queue<Goods, vector<int >,  decltype(cmp)> heap(cmp);
    int cnt = gds[n - 1].d, sum = 0;
    int i = n - 1;
    while (cnt) {
        while (i > -1 && gds[i].d == cnt) {
          heap.push(gds[i].p);
            i--;
        }

        if (!heap.empty()) {
            sum += heap.top();
            heap.pop();
        }
        cnt--;
    }
    
    cout << sum << endl;

    return 0;
}
