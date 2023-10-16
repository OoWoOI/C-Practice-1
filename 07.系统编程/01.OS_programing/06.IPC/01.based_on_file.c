/*************************************************************************
	> File Name: 01.based_on_file.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 02:19:44 PM CST
 ************************************************************************/
/*
*
* 问题：
*   1.文件指针创建失败:
*   2.IPC基于文件的实现
*
* */


#include"./common/head.h"
int main() {
    pid_t pid = 0;
    //打开文件:./letter
    FILE *fp = fopen("./letter", "rw+");

    //开启子进程
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    //子进程开启后的操作
    if (pid == 0) {
        sleep(1);
        //文件打开失败
        if (fp == NULL) {
            fprintf(stderr, "fp create error!\n");
            exit(1);
        }
        char buff[1024] = {0};
        fread(buff, 100, 10, fp);
        printf("%s", buff);
    } else {
        //文件打开失败
        if (fp == NULL) {
            fprintf(stderr, "fp create error!\n");
            exit(1);
        }
        fwrite("hello, My child!\n", 10, 2, fp);
    }
    
    return 0;
}
