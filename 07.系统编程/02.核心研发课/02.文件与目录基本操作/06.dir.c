/*************************************************************************
	> File Name: 06.dir.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 04:23:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[]) {
    char pathname[256] = {0};
    DIR *dir = NULL; 
    //如果没有参数选项，就默认打开本层目录
    if (argc == 1) {
       
        strcpy(pathname, ".");

    } else {
        strcpy(pathname, argv[1]);
    }
    
    //打开目录流
    if ((dir = opendir(pathname)) == NULL) {
        perror("opendir");
        exit(1);
    }
    //读取目录内容
    while (1) {
        struct dirent *dir_ptr;
        dir_ptr = readdir(dir);
        if (dir_ptr == NULL) {
            break;
        }
        printf("%s\n", dir_ptr->d_name);
    }
    
    closedir(dir);
    
    return 0;
}
