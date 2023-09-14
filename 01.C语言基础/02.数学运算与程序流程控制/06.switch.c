/*************************************************************************
	> File Name: 06.switch.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 08:44:00 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    switch(n) {
        case 1: {
            printf("one\n");
        } break;
        case 2: {
            printf("two\n");
        } break;
        case 3: {
            printf("three\n");
        } break;
        default :{
            printf("error\n"); 
        } break;
    }
    return 0;
}
