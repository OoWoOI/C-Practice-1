/*************************************************************************
	> File Name: hzoj599_两数之和.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 07:59:59 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;

int n, t, num[1000005];

//暴力解法
void slove_BM() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num[i] + num[j] == t) {
                printf("%d %d\n", i, j);
                return ;
            }
        }
    }
    return ;
}

//二分法
void slove_BS() {
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (num[mid] + num[i] == t) {
                printf("%d %d\n", i, mid);
                return ;
            }
            if (num[mid] < t - num[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    return ;
}

void slove_HASH() {
    unordered_map<int, int> hash_mp;
    for (int i = 0; i < n; i++) {
        hash_mp[num[i]] = i;
        if (hash_mp.count(t - num[i]) == 1) {
            printf("%d %d\n", hash_mp[t - num[i]], i);
            return ;
        }
    }

    return ;
}

void slove_DUBP() {
    int l = 0, r = n - 1;
    while (l < r) {
        if (num[l] + num[r] == t) {
            printf("%d %d\n", l, r);
            return ;
        }
        if (num[l] + num[r] < t) {
            l++;
        } else {
            r--;
        }
    }
    return ;
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    slove_BM();
    slove_BS();
    slove_HASH;
    slove_DUBP();
    return 0;
}
