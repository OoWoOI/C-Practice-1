/*************************************************************************
	> File Name: 02.nonblock.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 04:07:31 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age1 = 0, age2 = 0;    
    make_nonblock(0);
    int ret = scanf("%d", &age1);
    if (ret < 0) {
        perror("scanf");
    }
    make_block(0);
    scanf("%d", &age2);
    printf("my age1 = %d, age2 = %d!\n", age1, age2);
    return 0;
}
