/*************************************************************************
	> File Name: 01.pointer.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 10:08:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define pchar char* 
typedef char* ppchar;

//1.获取结构体成员变量的指针偏移量
#define offset(T, a) (long long)(&((T *)(NULL))->a)

struct Data {
    int a;
    double b;
    char c;
};


void output(int argc, char *argv[], char *env[]) {
    //输出参数argv
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    //输出系统环境变量
    for (int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);
        //指纹识别
        if (strncmp(env[i] ,"USER=", 5) == 0) {
            if (strncmp(env[i] + 5, "wj", 3)) {
                printf("you are permintion denie !\n");
                exit(0);
            }
        }
    }

    return ;
}

int main(int argc, char *argv[], char *env[]) {
    
    //1.通过指针改变原来的数据类型
    int nums1 = 0x616263;
    printf("%s\n", (char *)(&nums1));
    int nums2 = 0x61626364;
    printf("%s\n", (char *)(&nums2));
    //2.获取结构体成员变量的地址偏移量
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));
    printf("%lld\n", offset(struct Data, c));
    //3.关于typedef 与 define的区别
    pchar s1, s2;
    ppchar s3, s4;
    printf("s1 = %lu, s2 = %lu\n", sizeof(s1), sizeof(s2));
    printf("s3 = %lu, s4 = %lu\n", sizeof(s3), sizeof(s4));
    //4.输出主函数的传入参数
    output(argc, argv, env); 

    return 0;
}
