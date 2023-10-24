/*************************************************************************
	> File Name: 15.mmap.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Oct 2023 04:28:58 PM CST
 ************************************************************************/

#include "./common/head.h"


int main() {
    int fd = open("test.txt", O_RDWR);
    if (fd < 0) {
        perror("open file");
        exit(1);
    }

    char *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    p[0] = 'A';
    p[2] = 'A';
    p[3] = 'A';
    //((int *)(((char *)p) + 1))[0] = 0x30313233;
    munmap(p, 6);
    return 0;
}

