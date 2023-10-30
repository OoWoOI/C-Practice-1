/*************************************************************************
	> File Name: 10.waitOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 05:19:00 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        int n = 5;
        while (n--) {
            printf("I‘m child process!\n");
            sleep(1);
        }
        exit(3);
    } else {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if (WIFEXITED(stat_val)) {
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        } else if (WIFSIGNALED(stat_val)) {
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
        }

    }
    
    return 0;
}
