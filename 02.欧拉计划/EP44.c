/*************************************************************************
	> File Name: EP44.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 08:48:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

typedef long long ll;

ll Pentgonl(ll n) {
    return n * (3 * n - 1) / 2;
}

ll binary_search(ll (*func)(ll), ll n, ll x) {
    ll l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}


int main() {
    ll n = 2, pk = 0, D = INT32_MAX, pj = 0;    
    while ( Pentgonl(n) - Pentgonl(n - 1) < D) {
        pk = Pentgonl(n);
        for (int i = n - 1; i >= 1 && Pentgonl(n) - Pentgonl(i) < D; i--) {
            pj = Pentgonl(i);
            if (!binary_search(Pentgonl, n * 2, pk + pj)) continue;
            if (!binary_search(Pentgonl, n, pk - pj)) continue;
            D = pk - pj;
        }
        n++;
    }
    printf("%lld\n", D);
    return 0;
}
