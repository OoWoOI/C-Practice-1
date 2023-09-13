/*************************************************************************
	> File Name: 03.printf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Sep 2023 09:49:15 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    char str[100], str1[100];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%s\n", str);
        //输出到字符数组中
        sprintf(str1, "%s", str);
        //输出到文件中
        FILE *fp = fopen("./out", "wb");
        fprintf(fp, "str1 = %s", str);
        //输出到标准输出中去
        fprintf(stdout, "stdout = (%s)\n", str);
        //输出到标准错误输出中去
        fprintf(stderr, "strerr = (%s)", str);
        fclose(fp);
    }
    return 0;
}
