/*************************************************************************
	> File Name: 01.fork.c
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 02:46:13 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid) {
        printf("In Parent Proccess!\n");
    } else {
        printf("In Child Proccess!\n");
    }
    return 0;
}

