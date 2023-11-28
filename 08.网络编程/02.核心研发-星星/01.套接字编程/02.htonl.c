/*************************************************************************
	> File Name: 02.htonl.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 03:36:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>
//将主机字节序转换为网络字节序
int main() {
   int a = 0x12345678;
    printf("%#x\n", a);
    a = htonl(a);
    printf("%#x\n", a);
    return 0;
}
