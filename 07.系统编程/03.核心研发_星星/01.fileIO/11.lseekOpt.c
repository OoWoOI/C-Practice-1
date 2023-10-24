/*************************************************************************
	> File Name: 11.lseekOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 03:38:50 PM CST
 ************************************************************************/

#include"./common/head.h"
int main() {
    int fd;
    if ((fd = open("./test.txt", O_RDONLY)) < 0) {
        perror("OPEN");
        exit(1);
    }
    //通过lseek移动文件的读写指针
    char c;
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    int pos = lseek(fd, 1, SEEK_CUR);
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);

    printf("\npos = %d\n", pos);
    close(fd);
    return 0;
}
