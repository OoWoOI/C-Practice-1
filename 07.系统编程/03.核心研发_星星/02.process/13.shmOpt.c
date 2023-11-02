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
    
    int shmid = shmget(key, 20, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    printf("shmid = %d\n", shmid);
    
    char *shmp = shmat(shmid, NULL, 0);
    if (shmp < 0) {
        perror("shmp");
        exit(1);
    }
    printf("shmp = %p\n", shmp);
    /**
    
    //写数据
    //snprintf(shmp, 20, "hello\n");
    //读数据
    printf("%s", shmp);
    
    **/
    
    //进程间通信-IPC
    bzero(shmp, 20);
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid) {
        //parent process
        while (1) {
            scanf("%s", shmp);
            if (!strcmp("quit", shmp)) break;
        }
        wait(NULL);
    } else {
        //child process
        while (1) {
            if (!strcmp(shmp, "quit")) {
              break;
            }
            if (*shmp) {
                printf("child read：%s\n", shmp);
                bzero(shmp, 20);
            }
            sleep(1);
        }

    }
    

    shmdt(shmp);
    return 0;
}

