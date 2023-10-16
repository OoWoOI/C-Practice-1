/*************************************************************************
	> File Name: 02.shmget.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 03:23:57 PM CST
 ************************************************************************/

#include"./common/head.h"

struct shm_person{
    char name[20];
    int age;

};

int main() {
    struct shm_person *shared_memary = NULL;
    pid_t pid;
    key_t key = ftok(".", 1025);
    int shmid = shmget(key, sizeof(struct shm_person), IPC_CREAT | 0666);
    
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    if ((shared_memary = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    
    if ( (pid = fork()) < 0 ) {
        perror("fork");
        exit(1);
    }
    DBG("1\n");
    if (pid == 0) {
        sleep(1);
        printf("%s is %d years old!\n", shared_memary->name, shared_memary->age);
    } else {
        strcpy(shared_memary->name, "wdd");
        shared_memary->age = 18;
    }
    
    //访问了不该访问的内存空间，会报段错误
    

    return 0;
}
