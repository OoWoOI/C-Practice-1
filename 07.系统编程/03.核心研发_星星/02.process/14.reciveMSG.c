/*************************************************************************
	> File Name: 14.msgOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2023 03:57:53 PM CST
 ************************************************************************/

#include "./common/head.h"

#define MSGLEN 20

//消息结构体
typedef struct msgbuf{
    long mtype;
    char mtext[MSGLEN];
}MSG;

int main() {
    key_t key = ftok("./01.forkOpt.c", 9);
    if (key < 0) {
        perror("ftok");
        exit(1);
    }
    
    printf("%d\n", key);
        
    int mqid = msgget(key, IPC_CREAT | 0666);
    printf("mqid = %d\n", mqid);
    //接收消息
    MSG msg;
    msgrcv(mqid, &msg, MSGLEN, 2, 0);
    printf("mtype = %ld\n", msg.mtype);
    printf("msg = %s\n", msg.mtext);
    
    msgrcv(mqid, &msg, MSGLEN, 1, 0);
    printf("mtype = %ld\n", msg.mtype);
    printf("msg = %s\n", msg.mtext);

    return 0;
}
