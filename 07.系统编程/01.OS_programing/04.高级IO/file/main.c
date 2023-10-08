/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Sep 2023 03:09:39 PM CST
 ************************************************************************/

#include <IOblock.h>
#include <head.h>
int main() {
    int age = 18;
    make_nonblock(0);
    int cnt = 0;
    int ret = -1;
    while (1) {
        usleep(10000);
        ret = scanf("%d", &age);
        if (ret > 0) break;
        if (++cnt >= 300) break;
    }

    if (ret < 0) {
        perror("scanf");
    }
    printf("wdd is %d years old\n", age);

    return 0;
}
