/*************************************************************************
	> File Name: 03.select.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 02:20:29 PM CST
 ************************************************************************/

#include "head.h"

int main() {
     fd_set rfds;
    struct timeval tv;
    int ret;
    
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
   
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    ret =  select(1, &rfds, NULL, NULL, &tv);

    if (ret == -1) {
        perror("select()");
    } else if (ret) {
        printf("accept from scanf \n");
    } else {
        printf("No Data in Five sec !\n");
    }
    exit(EXIT_SUCCESS);
    return 0;
}
