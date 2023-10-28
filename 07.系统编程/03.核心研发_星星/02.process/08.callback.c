/*************************************************************************
	> File Name: 08.callback.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 06:25:25 PM CST
 ************************************************************************/

#include "./common/head.h"
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: cmd + filename + outfile\n");
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        perror("open file");
        exit(1);
    }

    dup2(fd, 0);
    close(fd);//关闭文件
    
    fd = open(argv[2], O_WRONLY);
    
    if (fd < 0) {
        perror("open file");
        exit(1);
    }
    
    dup2(fd, 1);
    close(fd);

    execl("./upper", "./upper", NULL);
    perror("execl");
    exit(1);
}
