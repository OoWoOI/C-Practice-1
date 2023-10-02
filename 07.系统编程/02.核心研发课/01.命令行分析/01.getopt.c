/*************************************************************************
	> File Name: 01.getopt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 03:29:40 PM CST
 ************************************************************************/

#include<head.h>
int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "ab:c::")) != -1) {
        switch (opt) {
            case 'a':
                printf("opt a found!\n");
                printf("ind = %d\n", optind);
                break;  
            case 'b':
                printf("opt b found!\n");
                printf("ind = %d\n", optind);
                printf("arg %s\n", optarg);
                break;
            case 'c':
                printf("opt c found!\n");
                printf("ind = %d\n", optind);
                printf("arg %s\n", optarg);
                break;
            default: 
                fprintf(stderr, "Usage : %s -a -b barg -c[carg]!\n", argv[0]);
                exit(1);
               // break;
        }
    }

    return 0;
}
