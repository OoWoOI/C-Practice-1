/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Sep 2023 03:05:04 PM CST
 ************************************************************************/

#include <IOblock.h>
#include <head.h>
#include <fcntl.h>

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }

    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);

}
