/*************************************************************************
	> File Name: 01.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 08:45:46 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int nums[10] = {0};
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums + n);
    
    sort(nums, nums + n, [](int a, int b){
        return a > b;
    });

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
