/*************************************************************************
	> File Name: EP43.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 07:58:12 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

long long isVal(int *a) {
    if (a[0] == 0) return 0;
    long long ans = a[0], nums = a[0];
    int p[7] = {2, 3, 5, 7, 11, 13, 17}, k = 0;
    for (int i = 1; i < 10; i++) {
        ans = ans * 10 + a[i]; 
        nums = nums * 10 +  a[i];
        if (i < 3) continue;
        nums -= 1000 * a[i - 3];
        if (nums % p[k++]) return 0;
    }
    return ans;
}

int main() {
    int num[10] = {0};
    long long sum = 0;
    for (int i = 0; i < 10; i++) num[i] = i;
    do {
        sum += isVal(num);
    } while (next_permutation(num, num + 10));
    printf("%lld\n", sum);
    return 0;
}
