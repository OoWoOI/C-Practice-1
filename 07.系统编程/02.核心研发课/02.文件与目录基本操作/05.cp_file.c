/*************************************************************************
	> File Name: 05.cp_file.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 04:35:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
    //如果参数选项少于3个，返回错误信息
    if (argc <= 3) {
        fprintf( stderr, "Usage : commond + %d\n", 3);
        exit(1);
    }
    //获取参数详细信息
    char rfile[512] = {0}, wfile[512] = {0};
    int opt;
    while ((opt = getopt(argc, argv, "r:w:")) != -1) {
        switch (opt) {
            case 'r':
                sprintf(rfile, "%s", optarg);
                break;
            case 'w':
                sprintf(wfile, "%s", optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
                break;
        }
    }
    
    //读取文件并复制到目标文件中去
    FILE *fpr, *fpw;
    fpr = fopen(rfile, "r+");
    fpw = fopen(wfile, "w+");
    
    if (!fpr) {
        fprintf( stderr,"fopen pathname %s is error!\n", rfile);
        exit(1);
    }

    if (!fpw) {
        fprintf(stderr, "fopen pathname %s is errror!\n", wfile);
        exit(1);
    }

    //求取文件大小
    fseek(fpr, 0, SEEK_END);
    size_t size = ftell(fpr);
    rewind(fpr);
    
    //读取数据并储存
    char *buff = malloc(sizeof(char) * (size + 5));
    fread(buff, 1, size, fpr);
    fwrite(buff, size, 1, fpw);

    //释放文件指针
    fclose(fpr);
    fclose(fpw);

    return 0;
}
