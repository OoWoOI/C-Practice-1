/*************************************************************************
	> File Name: 05.select.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 04:38:02 PM CST
 ************************************************************************/

#include"../common/head.h"
int main() {
    int age = 18;
    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    make_nonblock(0);
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    int ret;
    if ( (ret = select(1, &rfds, NULL, NULL, &tv)) <= 0) {
        fprintf(stderr, "Nothing read!\n");
        exit(1);
    }
     
    scanf("%d", &age);
    printf("oHo is %d year!\n", age);

    return 0;
}
