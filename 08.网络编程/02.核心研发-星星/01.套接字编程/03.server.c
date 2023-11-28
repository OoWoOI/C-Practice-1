/*************************************************************************
	> File Name: 03.server.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 02:28:27 PM CST
 ************************************************************************/

#include "./common/head.h"
#define SERV_PORT 8000

int main() {
    struct sockaddr_in serveraddr;
    int listenfd, connfd; 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    
    listen(listenfd, 3);
    printf("Accpeting ``connections...\n");
    while (1) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr);
    }
    return 0;
}
