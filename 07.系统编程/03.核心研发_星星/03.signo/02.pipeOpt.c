/*************************************************************************
	> File Name: 02.pipeOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2023 03:50:13 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    int pfd[2];
    
    if (pipe(pfd) < 0) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid) {
        //father process
        close(pfd[0]);
        close(pfd[1]);
        
        int sts;
        wait(&sts);

        if (WIFSIGNALED(sts)) {
            printf("exit signal = %d\n", WTERMSIG(sts));
        } else {
            printf("exit other ways !\n");
        }
        
    } else {
        //child process
        sleep(3);
        close(pfd[0]);
        write(pfd[1], "hello\n", 6);
        sleep(3);
    }
    
    return 0;
}

