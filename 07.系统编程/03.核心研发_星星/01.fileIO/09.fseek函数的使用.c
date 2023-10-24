/*************************************************************************
	> File Name: 09.fseek函数的使用.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 03:08:07 PM CST
 ************************************************************************/

#include"./common/head.h"
int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "w+");//获取指定文件的指针
    
    if (!fp) {
        perror("file open");
        exit(1);
    }

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    
   // fseek(fp, 0, SEEK_SET);
    rewind(fp);
    fputc('X', fp); 
    fputc('Y', fp); 
    fputc('Z', fp); 
    fclose(fp);
    return 0;
}
