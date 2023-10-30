/*************************************************************************
	> File Name: 13.shmOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 08:00:57 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    key_t key = ftok("./01.forkOpt.c", 9);
    if (key < 0) {
        perror("ftok");
        exit(1);
    }

    printf("key_t = %d\n", key);
    
    int shmid = shmget(key, 20, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    printf("shmid = %d\n", shmid);
    return 0;
}

