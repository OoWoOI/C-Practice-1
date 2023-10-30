/*************************************************************************
	> File Name: 12.popenOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 07:26:24 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    FILE *fp = popen("./upper", "w");
    if (!fp) {
        perror("popen");
        exit(1);
    }
    
    fprintf(fp, "hello upper!\n");

    pclose(fp);

    return 0;
}

