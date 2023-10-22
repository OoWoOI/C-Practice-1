/*************************************************************************
	> File Name: 07.fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 03:59:44 PM CST
 ************************************************************************/

#include"./common/head.h"
int main(int argc, char **argv) {
    
    if (argc < 2) {
        printf("usage:cmd + filename\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("open");
        exit(1);
    }

    char c = 0;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}
