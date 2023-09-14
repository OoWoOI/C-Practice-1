/*************************************************************************
	> File Name: 07.switch_1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 08:47:10 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("one ");
        case 2:
            printf("two ");
        case 3:
            printf("three\n");
            break;
        default : {
            printf("erro\n");
        }break;
    }
    return 0;
}
