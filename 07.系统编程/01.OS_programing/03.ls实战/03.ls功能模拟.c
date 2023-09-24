/*************************************************************************
	> File Name: 03.ls功能模拟.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2023 10:37:07 AM CST
 ************************************************************************/

#include "../common/head.h"

int l_flag = 0;
int a_flag = 0;

void do_ls(const char *name);


int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': {
                a_flag = 1;
            } break;
            case 'l': {
                l_flag = 1;
            } break;
            default : {
                fprintf(stderr, "Usage : %s [-al] [args...]\n", argv[0]);
                exit(1);
            } break;
        }
    }
    
    argc -= (optind - 1);
    argv += (optind - 1);
    DBG("argc = %d, argv[1] = %s\n", argc, argv[1]);
    
    if (argc == 1) {
        do_ls(".");
    } else {
        for (int i = 1; i < argc; i++) {
            do_ls(argv[i]);
        }
    }
    return 0;
}

void do_ls(const char *name) {
    DBG("%s\n", name);
    DIR *dir = NULL;
    if ((dir = opendir(name)) == NULL) {
        DBG("Open Error\n"); 
        //目录打开失败
        if (access(name, R_OK) == 0) {
            if (l_flag == 1) {
                //是文件，输出
                do_stat(name);
            } else {
                //不是文件，就输出目录名
                printf("%s\n", name);
            }
        }

    } else {
        DBG("Open Success!\n");
    } 
    return ;
}
