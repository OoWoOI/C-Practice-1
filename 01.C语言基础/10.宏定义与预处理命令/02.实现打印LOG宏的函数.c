/*************************************************************************
	> File Name: 02.实现打印LOG宏的函数.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 07:55:10 PM CST
 ************************************************************************/

#include<stdio.h>

//条件式编译

#ifdef DEBUG

#define LOG(frm, arg...) {\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##arg);\
}

#else 
#define LOG(frm, arg...)

#endif

int main() {
    LOG("hello word!\n");
    return 0;
}
