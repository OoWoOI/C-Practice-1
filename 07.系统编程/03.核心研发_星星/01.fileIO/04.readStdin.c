/*************************************************************************
	> File Name: 04.readStdin.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 02:32:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int agrc, char **argv) {
    char  buf[20];
    int n;

    n = read(STDIN_FILENO, buf, 10);

    if (n < 0) {
        perror("READ STDIN");
        exit(1);
    }

    printf("read %d bytes\n", n);

    for (int i = 0; i < n; i++) {
        printf("%c", buf[i]);
    }
    
    putchar(10);

    return 0;
}
