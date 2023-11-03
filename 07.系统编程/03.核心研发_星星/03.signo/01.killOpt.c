/*************************************************************************
	> File Name: 01.killOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2023 03:16:16 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("kill");
        exit(1);
    }
    
    if (pid) {
        //father process
        sleep(3);
        
        if (kill(pid, SIGQUIT) < 0) {
            perror("kill");
            exit(1);
        }

        int sts;
        wait(&sts);
        
        if (WIFSIGNALED(sts)) {
            printf("child terminate by signal %d\n", WTERMSIG(sts));
        } else {
            printf("child exit other reasons!\n");
        }

    } else {
        //child process
        while (1) {
            printf("child sleep 1 sec\n");
            sleep(1);
        }
        
    }


    return 0;
}

