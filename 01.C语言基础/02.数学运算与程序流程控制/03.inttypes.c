/*************************************************************************
	> File Name: 03.inttypes.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 07:48:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main() {
    int8_t a = 11;
    int b  = 22;
    int16_t c = 33;
    int32_t d = 44;
    int64_t e = 55;
    printf("8 = %lu int = %lu 16 = %lu 32 = %lu 64 = %lu\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e));
    printf("%" PRId8 "\n", a);//对于特殊的int数据类型
    printf("hello" "word\n");
    return 0;
}
