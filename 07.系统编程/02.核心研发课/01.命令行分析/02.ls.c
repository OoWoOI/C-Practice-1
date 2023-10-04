/*************************************************************************
	> File Name: ./01.命令行分析/02.ls.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 04:36:52 PM CST
 ************************************************************************/

#include<head.h>

//实现ls命令的基本功能：
// -al -l
int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "a::l:"))) {
        switch (opt) {
            case 'a': {
                printf("optind : %d\n", optind);
                printf("%s\n", optarg);
            }break;
            case 'l': {
                printf("optind : %d\n", optind);
                printf("%s\n", optarg);
            } break;
            default: {
                perror("open fail !");
                exit(1);
            }break;
        }
    }  
    
    return 0;
}
