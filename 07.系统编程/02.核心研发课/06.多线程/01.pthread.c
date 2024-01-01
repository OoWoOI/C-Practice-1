/*************************************************************************
	> File Name: 01.pthread.c
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Dec 2023 02:29:34 PM CST
 ************************************************************************/

#include "head.h"
struct Arg {
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg *argin = (struct Arg *)arg;
    printf("%s is %d years old! \n", argin->name, argin->age);
   // return ;
}

int main() {
    pthread_t thread;
    struct Arg arg;
    memset(&arg, 0, sizeof(arg));
    arg.age = 18;
    strcpy(arg.name, "suyelu");
    pthread_create(&thread, NULL, print, (void *)&arg);
    usleep(1000);
    
    return 0;
}
