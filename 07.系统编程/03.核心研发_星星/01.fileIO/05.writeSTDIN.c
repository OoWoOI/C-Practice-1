/*************************************************************************
	> File Name: 05.writeFile.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 03:00:07 PM CST
 ************************************************************************/

#include"./common/head.h"
int main(int argc, char **argv) {
    char buff[20];
    ssize_t n = read(STDIN_FILENO, buff, 10);
    if (n < 0) {
        perror("Read");
        exit(1);
    }
    
    write(STDOUT_FILENO, buff, n);
    return 0;
}

