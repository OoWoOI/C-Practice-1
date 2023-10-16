/*************************************************************************
	> File Name: 03.shmget-1.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 03:54:21 PM CST
 ************************************************************************/

#include"./common/head.h"

struct person{
    char name[20];
    int age;
};

int main() {
    key_t key = ftok(".", 1025);
    int shmid;
    if ((shmid = shmget(key, sizeof(struct person), 0)) < 0) {
        perror("shmget");
        exit(1);
    }

    struct person *sh = shmat(shmid, NULL, 0);
    printf("%s is %d years old!\n", sh->name, sh->age);

    return 0;
}
