/*************************************************************************
	> File Name: 01.hello.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Oct 2023 03:38:42 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int i;
    for (i = 0; i < 1024; i++) {
        fputc('A', stdout);
    }

    fputc('A', stdout);//行缓冲机制，遇到换行就触发系统调用
    fputc('\n',stdout);
    fputc('C', stderr);//无缓冲机制，直接调用系统接口
    while (1) {
        
    }

    return 0;
}
