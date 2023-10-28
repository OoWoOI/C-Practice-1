/*************************************************************************
	> File Name: 05.envOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 05:09:42 PM CST
 ************************************************************************/

#include "./common/head.h"
int main() {
   
   /** 
    extern char **environ;
    int i;
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
    **/
    
    printf("get = %s\n", getenv("PATH"));
    setenv("PATH", "hell", 1);
    printf("get = %s\n", getenv("PATH"));
    return 0;
}
