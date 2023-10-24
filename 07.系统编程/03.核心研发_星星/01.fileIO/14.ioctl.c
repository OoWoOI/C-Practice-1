/*************************************************************************
	> File Name: 14.ioctl.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Oct 2023 03:51:08 PM CST
 ************************************************************************/

#include "./common/head.h"


int main() {
    struct winsize size;
    if (!isatty(1)) {
        printf("1 is not tty\n");
        exit(1);
    }

    if (ioctl(1, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
    
    return 0;
}

