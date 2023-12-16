/*************************************************************************
	> File Name: 03.popen.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Dec 2023 02:43:56 PM CST
 ************************************************************************/

#include "head.h"
int main() {
    FILE *fp;
    if ((fp = my_popen("cat ./03.popen.c", "r")) == NULL) {
        perror("popen()");
        exit(1);
    }
    
    char buf[512] = {0};
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
        memset(buf, 0, sizeof(buf));
    }
    
    my_pclose(fp);
    
    return 0;
}
