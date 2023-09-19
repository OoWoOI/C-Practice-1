/*************************************************************************
	> File Name: 02.输出带颜色的内容.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 10:23:40 AM CST
 ************************************************************************/

#include "../common/head.h"

int main() {
     DBG(GREEN"这是绿色"NONE"\n");
     DBG(RED"这是红色"NONE"\n");
     DBG(BLUE"这是蓝色"NONE"\n");
     DBG(PINK"这是粉色"NONE"\n");
    return 0;
}
