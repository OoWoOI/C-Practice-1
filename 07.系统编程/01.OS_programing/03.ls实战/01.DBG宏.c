/*************************************************************************
	> File Name: 01.DBG宏.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 10:17:32 AM CST
 ************************************************************************/

#include "../common/head.h"
int main() {
    int age = 19;
    char name[20] = "wdd";
    DBG("this is Debug information.\n");
    DBG("%s is %d years old.\n", name, age);
    return 0;
}
