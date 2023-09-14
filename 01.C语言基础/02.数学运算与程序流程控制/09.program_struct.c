/*************************************************************************
	> File Name: 09.program_struct.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 09:05:07 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal\n");
    } else {
        printf("equal\n");
    }
    
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    printf("%d %d\n", a, b);

    return 0;
}
