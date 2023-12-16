/*************************************************************************
	> File Name: 01.shmget.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 03:15:30 PM CST
 ************************************************************************/

#include "head.h"
int main() {
    pid_t pid;
    int shmid;
    char *share_memory = NULL;
    key_t key = ftok("./01.shmget.c", 123);
    if ((shmid = shmget(key, 4096, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
    }
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        while (1) {
            sleep(2);
            printf("<Parent> : ");
            scanf("%[^\n]s", share_memory);
            getchar();
        }
    } else {
        while (1) {
            if (strlen(share_memory)) printf("<Chaild> : %s\n", share_memory);
            memset(share_memory, 0, 4096);
        }
    }

    return 0;
}
