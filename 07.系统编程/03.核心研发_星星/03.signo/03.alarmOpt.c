/*************************************************************************
	> File Name: 03.alarmOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2023 04:02:24 PM CST
 ************************************************************************/

#include"./common/head.h"

int main() {
    alarm(5);
    sleep(3);
    unsigned int left = alarm(5);
    printf("left = %d\n", left);
    while (1) {
        printf("sleep 1 sec!\n");
        sleep(1);
    }
    return 0;
}

