/*************************************************************************
	> File Name: 04.select_sleep.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 04:27:20 PM CST
 ************************************************************************/

#include"../common/head.h"

int my_sleep(int sec) {
    struct timeval tv;
    tv.tv_sec = sec;
    tv.tv_usec = 0;
    int ret = select(0, NULL, NULL, NULL, &tv);
    if (ret < 0) {
        return -1;
    }
    return 0;
}

int main() {
    my_sleep(10);
    printf("End!\n");

    return 0;
}
