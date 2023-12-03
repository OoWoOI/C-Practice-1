/*************************************************************************
	> File Name: 01.getopt-1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 04:24:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
    int opt;
    //optstring这个参数中，参数选项后面加了":"则必须加参数，
    //否则会将后面得参数选项当成前面的参数
    while ((opt = getopt(argc, argv, "ab:c::")) != -1) {
        switch (opt) {
            case 'a':
                printf("arg a is found!\n");
                printf("ind = %d\n", optind);
                printf("arg = %s\n", optarg);
                break;
            case 'b':
                printf("arg b is found!\n");
                printf("ind = %d\n", optind);
                printf("arg = %s\n", optarg);
                break;
            case 'c':
                printf("arg c is found!\n");
                printf("ind = %d\n", optind);
                printf("arg = %s\n", optarg);
                break;
            default:
                fprintf(stderr, "arg not found!\n");
                break;
        }
    }
    
    return 0;
}
