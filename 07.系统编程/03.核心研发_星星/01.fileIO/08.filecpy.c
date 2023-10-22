/*************************************************************************
	> File Name: 08.filecpy.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 04:21:46 PM CST
 ************************************************************************/

#include"./common/head.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("usage: cmd + srcfilename + dstfilename\n");
        exit(1);
    }
    //打开文件
    
    FILE *fp1 = fopen(argv[1], "r+");
    FILE *fp2 = fopen(argv[2], "w+");

    if (!fp1) {
        perror("open srcFile");
        exit(1);
    }

    if (!fp2) {
        perror("open dstFile");
        exit(1);
    }
    

  //  char buff[1024];
    char c;
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c ,fp2);
    }
    
    fclose(fp1);
    fclose(fp2);

    return 0;
}

