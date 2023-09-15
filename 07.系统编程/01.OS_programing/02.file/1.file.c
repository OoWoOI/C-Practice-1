/*************************************************************************
	> File Name: 1.file.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 09:55:37 AM CST
 ************************************************************************/

#include"../common/head.h"
//Usage cp file1. file2
int main(int argc, char **argv) {
    char buff[10] = {0};
    int fd_in;
    int fd_out;
    if (argc != 3) {
        fprintf(stderr, "Usage : %s file1 file2\n", argv[0]);
        exit(1);
    }
    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    } 
    
    if ((fd_out = open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0644)) < 0) {
        perror("out file");
        exit(1);
    }

    size_t buff_size = sizeof(buff);

    while (1) {
        int rsize = read(fd_in, buff, buff_size - 1);
        if (rsize < 0) {
            perror("read");
            exit(1);
        }

        if (rsize == 0) {
            break;
        }
        //printf("%s", buff);
       int wsize = write(fd_out, buff, rsize);    
        if (wsize < 0) {
            perror("write to out file");
            exit(1);
        }
        memset(buff, 0, buff_size);
    }
    
    //关闭已经打开的文件
    close(fd_out);
    close(fd_in);
    return 0;
}
