/*************************************************************************
	> File Name: 01.nonbloc.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 03:30:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main() {
    int age;
    int flag = fcntl(0, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(0, F_SETFL, flag);
    scanf("%d", &age);
    printf("my girl is %d years old!\n", age);
    return 0;
}
