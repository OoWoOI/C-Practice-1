/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 03:12:24 PM CST
 ************************************************************************/

#include"head.h"
#include"common.h"

int make_nonblock(int fd) {
    int flag;
    if ( (flag = fcntl(fd, F_GETFL)) < 0 ) {
        return -1;//exit(1)会结束整个程序，但是return -1只会结束当前函数的执行
    }
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int make_block(int fd) {
    int flag;
    if ( (flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}
