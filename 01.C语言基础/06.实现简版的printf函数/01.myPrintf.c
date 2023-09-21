/*************************************************************************
	> File Name: 01.myPrintf.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 08:37:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>

#define PUTC(a) putchar(a), cnt++

//实现简版的printf函数：字符串、%s、%d

int myprintf(const char *frm, ...){
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch(frm[i]) {
            case '%': {
                switch(frm[i + 1]) {
                    case 'd': {
                        int x = va_arg(arg, int);
                        if (x < 0) PUTC('-');
                        unsigned int xx = (unsigned int) x;
                        int num[25] = {0};
                        while (xx){
                            num[++num[0]] = (xx % 10);
                            xx /= 10;
                        }
                         
                        for (int k = num[0]; k >= 1; k--) {
                           PUTC(num[k] + '0'); 
                        }
                        i++;
                    } break;
                    case 's': {
                        char *str = va_arg(arg, char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                        i++;
                    } break; 
                    case '%': {
                        PUTC(frm[i]);
                    } break;
                    default : {
                        PUTC(frm[i]); 
                    } break;

                }
            } break;
            default : {
                PUTC(frm[i]);
            } break;

        }

    }
    va_end(arg);
    return cnt;
}

int main() {
    //字符串
    int ret;
    ret = printf("hello\n");
    printf("%d\n", ret);
    ret = myprintf("hello\n");
    printf("%d\n", ret);

    //%d
    int val = 123;
    ret = printf("%d\n", val);
    printf("%d\n", ret);
    ret = myprintf("%d\n", val);
    printf("%d\n", ret);
    val = INT32_MAX;
    ret = printf("%d\n", val);
    printf("%d\n", ret);
    ret = myprintf("%d\n", val);
    printf("%d\n", ret);
    
    val = INT32_MIN;
    ret = printf("%d\n", val);
    printf("%d\n", ret);
    ret = myprintf("%d\n", val);
    printf("%d\n", ret);
    return 0;
}
