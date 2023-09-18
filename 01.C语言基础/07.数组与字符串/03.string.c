/*************************************************************************
	> File Name: 03.string.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 08:33:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>

void test_sscanf() {
    char str1[] = "123 456 789 987";
    char str2[100];
    int a, b, c, d;

    /*
    //方式1.直接使用sscanf格式读取
    sscanf(str1, "%d %d %d %d", &a, &b, &c, &d);
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);    
    */
   
    
    //方式2.每次读取完覆盖前面的数据
    sscanf(str1, "%d%[^$]s", &a, str1);
    sscanf(str1, "%d%[^$]s", &b, str1);
    sscanf(str1, "%d%[^$]s", &c, str1);
    sscanf(str1, "%d%[^&]s", &d, str1);
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);     
    
    int offset = 0;
    offset += sprintf(str2 + offset, "%d", a);
    offset += sprintf(str2 + offset, " %d", b);
    offset += sprintf(str2 + offset, " %d", c);
    offset += sprintf(str2 + offset, " %d", d);
    printf("str2 = %s\n", str2);    
    return ;
}

//获取长度
uint64_t strlen1(const char *str) {
    uint64_t cnt = 0;
    while (str[cnt]) cnt++;
    return cnt;
}


//比较两个字符串大小
int strcmp1(const char *str1, const char *str2) {
    uint64_t i = 0;
    for (; str1[i] && str2[i]; i++) {
        if (str1[i] - str2[i]) return str1[i] - str2[i] < 0;
    }

    return str1[i] - str2[i] < 0;
}




int main() {
    char str[100];
    int a;
    //十进制数转十六进制
    
    /**
    while (~scanf("%d", &a)) {
        sprintf(str, "%x", a);
        printf("%s has %d digites\n", str, (int)strlen(str));
    }
    **/

    //将字符串转成数字
    //test_sscanf();
    
    //自主实现strlen、strcmp功能

    printf("%"PRIu64"\n", strlen1("hello word"));
    printf("%d\n", strcmp1("hello", "word"));
    return 0;
}
