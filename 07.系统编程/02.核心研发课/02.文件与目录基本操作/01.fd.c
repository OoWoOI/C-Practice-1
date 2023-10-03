/*************************************************************************
	> File Name: 01.fd.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 04:14:01 PM CST
 ************************************************************************/

#include<head.h>
int main(int argc, char *argv[]) {
    int fd;
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "Eroor!\n");
        perror("open");
        exit(1);
    }
    perror("open2");
    return 0;
}
