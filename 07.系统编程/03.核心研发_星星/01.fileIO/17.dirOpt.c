/*************************************************************************
	> File Name: 17.dirOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Oct 2023 03:27:38 PM CST
 ************************************************************************/

#include "./common/head.h"

void printDIR(char *dirname) {
    
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    char pathname[4096] = {0}; 
    if (!(dir = opendir(dirname))) {
        perror("opendir");
        exit(1);
    }

    while (dp = readdir(dir)) {
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) 
            continue;
        
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        if(stat(pathname, &st) < 0) {
            perror("stat");
            exit(1);
        }
        if (S_ISDIR(st.st_mode))  
            printDIR(pathname);
        else
            printf("%s\n", dp->d_name);    
    }
    putchar(10);
    closedir(dir);
    return ;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: cmd + pathname");
        exit(1);
    }
    
    printDIR(argv[1]); //递归打印输出目录下的文件名 
    return 0;
}
