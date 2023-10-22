/*************************************************************************
	> File Name: 06.nonblock.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 03:35:49 PM CST
 ************************************************************************/

#include"./common/head.h"

int main(int argc, char **argv) {
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open");
        exit(1);
    } 
    
    size_t n;
    char buf[10];
    
    while (1) {
        n = read(fd, buf, 10);
        if (~n) {
            printf("read %d bytes\n", n);
            write(STDOUT_FILENO, buf, n);
            putchar(10);
            break;
        }

        if (errno != EAGAIN) {
            perror("READ / dev/tty");
            exit(1);
        }
        write(STDOUT_FILENO, "try try?\n", 9);
        sleep(1);
    }


    close(fd);
    return 0;
}
