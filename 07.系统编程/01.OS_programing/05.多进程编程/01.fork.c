/*************************************************************************
	> File Name: 01.fork.c
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Oct 2023 04:53:48 PM CST
 ************************************************************************/

#include"./common/head.h"
int main() {
    printf("hello word!");
    pid_t pid = 0;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } 
    
    if (pid == 0) {
        printf("I'm child!\n");
    } else {
        printf("I'm parent!\n");
    }
        
    return 0;
}

