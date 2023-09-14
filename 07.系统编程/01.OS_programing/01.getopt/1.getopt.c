/*************************************************************************
	> File Name: 1.getopt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 09:46:22 AM CST
 ************************************************************************/
#include "./common/head.h"
int main(int argc, char **argv) {
    char output[20] = {0};
    char input[20] = {0};
    if (argc < 2) {
        fprintf( stderr, "Usage : %s -o file\n", argv[0]);//打印错误
        exit(1);
    }
    int opt;
    while ((opt = getopt(argc, argv, "o:O::")) != -1) {
        switch(opt) {
            case 'o': {
                strcpy(output, optarg);
            } break;
            case 'O': {
                strcpy(output, optarg);
            } break;
            default : {
                fprintf(stderr, "Usage : %s -o file", argv[0]);
                exit(1);
            } break; 
        }
    }
    printf("input file = %s\n", argv[optind]);
    printf("output = %s\n", output);

    return 0;
}
