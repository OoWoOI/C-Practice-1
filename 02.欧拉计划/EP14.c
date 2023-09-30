/*************************************************************************
	> File Name: EP14.c
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Sep 2023 08:05:36 PM CST
 ************************************************************************/

#include<stdio.h>

#define max_n 1000000

typedef long long ll;

ll keep[max_n + 5] = {0};

ll get_len(ll n) {
    if (n == 1) return 1;
    if (n <= max_n && keep[n]) return keep[n];
    ll ret = 0;
    if ((n & 1)) ret = get_len(3 * n + 1) + 1;
    else ret = get_len(n >> 1) + 1;
    if (n <= max_n) keep[n] = ret;
    return ret;
}

int main() {
    ll num = 0, len = 0;
    for (ll i = 1; i < max_n; i++) {
        ll ret = get_len(i);
        if (ret < len) continue;
        num = i;
        len = ret;
    }
    printf("num = %lld, len = %lld\n", num, len);
    return 0;
}
