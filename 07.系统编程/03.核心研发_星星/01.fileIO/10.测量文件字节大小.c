/*************************************************************************
	> File Name: 10.测量文件字节大小.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 03:25:19 PM CST
 ************************************************************************/

#include"./common/head.h"

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("open file");
        exit(1);
    }

    //实现文件大小测量工作
    fseek(fp, 0, SEEK_END);
    printf("pos = %d\n", (int)ftell(fp));
    return 0;
}
