/*************************************************************************
	> File Name: EP32.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 08:48:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 10000


int digits(int n) {
    return floor(log10(n)) + 1;
}

int add_to_num(int n, int *num) {
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int is_val(int a, int b)  {
    if (digits(a) + digits(b) + (digits(a * b)) != 9) return 0;
    int num[10] = {0};
    int flag = 1;
    num[0] = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(a * b, num); 
    return flag;
}

int keep[max_n + 5];

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!is_val(a, b)) continue;
            if (keep[a * b]) continue;
            sum += a * b;
            keep[a * b] = 1;
        }
    }    
    printf("%d\n", sum);
    return 0;
}
