/*************************************************************************
	> File Name: 3.ffile.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 11:09:11 AM CST
 ************************************************************************/

#include"../common/head.h"
//实现fopen
int main(int argc, char **argv) {
    if (argc < 3) {
        perror("参数缺失");
        exit(1);
    }
    FILE *fp_in = fopen(argv[1], "r+");//输入文件    
    if (fp_in == NULL) {
        perror("文件打开失败");
        exit(1);
    }
    char buff[10] = {0};
    int buff_size = sizeof(buff);
    while (1) {
       int rsize =  fread(fb_out, buff, buff_size, fb_in);
       printf("%s", buff);
        if (rsize < 0) {
            perror("读取失败");
            exit(1);
        }

       if (rsize == 0) {
            break;
       }
       memset(buff, 0, buff_size);
    }


    return 0;
}
