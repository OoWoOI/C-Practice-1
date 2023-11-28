/*************************************************************************
	> File Name: hzoj388.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 08:15:56 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int n, m;
long long M[MAX_N + 5], N[MAX_N + 5], ans;

int bs(long long x) {
    int l = 0, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (N[mid] == x) return mid;
        if (N[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &M[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &N[i]);
    }

    sort(N, N + n);
    for (int i = 0; i < m; i++) {
       int indx = bs(M[i]);
        if (indx != -1) {
            if (ans != 0) printf(" ");
            printf("%lld", M[i]);
        }
       ans += ( indx != -1) ? M[i] : 0;
    }
    
    printf("\n%lld\n", ans);
    return 0;
}
