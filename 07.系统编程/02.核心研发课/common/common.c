/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 03:53:30 PM CST
 ************************************************************************/

#include "head.h"

int make_nonblock(int fd) {
    int flag = fcntl(fd, F_GETFL);
    if (flag < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    if ((fcntl(fd, F_SETFL, flag)) < 0) {
        return -1;
    }
    return 0;
}


int make_block(int fd) {
    int flag = fcntl(fd, F_GETFL);
    if (flag < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    if ((fcntl(fd, F_SETFL, flag)) < 0) {
        return -1;
    }
    return 0;
}
