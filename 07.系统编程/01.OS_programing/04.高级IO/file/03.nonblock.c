/*************************************************************************
	> File Name: 03.nonblock.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 03:30:38 PM CST
 ************************************************************************/

#include"../common/head.h"

int main() {
    int age = 18;
    
    make_nonblock(0);
    
    int cnt = 0;
    int ret = -1;
    //实现功能：30s内，等待用户输入，检测用户输入后，立即输出
    //          否则等到30s结束后输出错误信息，并使用默认值
    while (cnt <= 30 && ret < 0) {
        sleep(1);
        ret = scanf("%d", &age);
        cnt++;
    }

    if (ret < 0) {
        perror("scanf");
    }
    
    printf("oHo is %d\n", age);
    return 0;
}

