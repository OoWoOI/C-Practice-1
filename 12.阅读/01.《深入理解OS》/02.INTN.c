/*************************************************************************
	> File Name: 02.INTN.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Dec 2023 04:50:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main() {
    int32_t a = 123;
    int64_t b = 240;

    printf("a = %" PRId32 ", b = %" PRId64 "\n", a, b);
    
    return 0;
}
