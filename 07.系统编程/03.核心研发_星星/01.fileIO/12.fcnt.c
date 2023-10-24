/*************************************************************************
	> File Name: 12.fcnt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 04:23:30 PM CST
 ************************************************************************/

#include"./common/head.h"

int main(int argc, char *argv[]) {
    int flags;

    if ((flags = fcntl(STDIN_FILENO, F_GETFL)) < 0) {
        perror("fcntl get flags");
        exit(1);
    }
    flags |= O_NONBLOCK; 
    if ((flags = fcntl(STDIN_FILENO, F_SETFL, flags)) < 0) {
        perror("fcntl set flags");
        exit(1);
    }

    char buf[10];
    ssize_t n;

    while (1) {
        n = read(0, buf, 5);
        if (n >= 0) break;
        if (errno != EAGAIN) {
            perror("read");
            exit(1);
        }

        write(1, "once again ?\n", 13);
        sleep(1);
    }
    write(1, buf, n);

    return 0;
}

