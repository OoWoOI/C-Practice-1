/*************************************************************************
	> File Name: 04.位运算与优先级.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 08:13:18 PM CST
 ************************************************************************/

#include<stdio.h>
int main()  {
    int a = 6, b = 3, c;
    int *p = &a;
    printf("%d %d\n", (*p)++, (b + a));
    
    //位运算：&1操作，判断奇偶性, 异或交换元素
    scanf("%d", &c);
    if (c & 1) {
        printf("odd\n");
    } else {
        printf("even\n");
    }
    
    //交换a和b的元素
    printf("%d %d\n", a, b);
    a ^= b; b ^= a, a ^= b;
    printf("%d %d\n", a, b);

    return 0;
}
