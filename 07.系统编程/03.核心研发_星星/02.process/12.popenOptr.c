/*************************************************************************
	> File Name: 12.popenOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 07:26:24 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    FILE *fp = popen("cat ./test.txt", "r");
    if (!fp) {
        perror("popen");
        exit(1);
    }
    
    int c;

    while (~(c = fgetc(fp))) {
        char w = toupper(c);
        putchar(w); 
    }
    
    pclose(fp);

    return 0;
}

