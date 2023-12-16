/*************************************************************************
	> File Name: 01.数据类型的字节输出.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 04:37:36 PM CST
 ************************************************************************/

#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    return ;
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
    return ;
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
    return ;
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
    return ;
}

int main() {
    int a = 2;
    float  b = 2.1;
    void *c = &a;
    short x = 12345;
    short mx = -x;
    
    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));

    show_int(a);
    show_float(b);
    show_pointer(c);
    return 0;
}
