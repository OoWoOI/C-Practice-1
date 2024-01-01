/*************************************************************************
	> File Name: 02.pthread.c
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Dec 2023 03:10:47 PM CST
 ************************************************************************/

#include "head.h"
#define INS 100

struct Arg {
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg argin;
    argin = *(struct Arg *)arg;
    printf("%s is %d years old!\n", argin.name, argin.age);
}

int main() {
    pthread_t thread;
    pthread_t *tid = calloc(INS + 5, sizeof(pthread_t));
    struct Arg *arg = calloc(INS + 5, sizeof(struct Arg));
    for (int i = 1; i <= INS; i++) {
        strcpy(arg[i].name, "suyelu");
        arg[i].age = i;
        pthread_create(&tid[i], NULL, print, &arg[i]);
    }
    
    for (int i = 1; i <= 100; i++) {
        pthread_join(tid[i], NULL);
    }
    
    return 0;
}
