/*************************************************************************
	> File Name: 06.execOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 05:40:49 PM CST
 ************************************************************************/

#include "./common/head.h"
int main() {
    execlp("ls", "ls", "-a", "-l", NULL);
    perror("execlp");
    exit(1);    
}
