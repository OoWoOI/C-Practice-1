/*************************************************************************
	> File Name: 03.exec.c
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 04:01:14 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid == 0) {
        execlp("cat", "cat", "./01.fork.c", NULL);
        printf("hahah!\n");
    } else {
        wait(NULL);
    }
    return 0;
}
