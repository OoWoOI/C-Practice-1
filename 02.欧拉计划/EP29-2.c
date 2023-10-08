/*************************************************************************
	> File Name: EP29-2.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 08:20:42 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    return !b ? gcd(b, a % b) : a;  
}

int main() {
    printf("%d\n", gcd(2, 4));
    
    return 0;
}
