/*************************************************************************
	> File Name: my_popen.h
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Dec 2023 03:09:55 PM CST
 ************************************************************************/

#ifndef _MY_POPEN_H
#define _MY_POPEN_H
FILE *my_popen(const char *cmd, const char *type);
int my_pclose(FILE *fp);
#endif
