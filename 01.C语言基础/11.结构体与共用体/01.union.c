/*************************************************************************
	> File Name: 01.union.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 09:18:33 PM CST
 ************************************************************************/

//实现ip转整数功能

#include<stdio.h>

union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int main() {
    union IP p; 
    char str[25];
    int a[4];
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", a, a + 1, a + 2, a + 3);
        p.ip.a1 = a[3];
        p.ip.a2 = a[2];
        p.ip.a3 = a[1];
        p.ip.a4 = a[0];
        printf("%u\n", p.num);
    }

    return 0;
}
