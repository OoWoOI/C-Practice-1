/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 10:11:09 AM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>


//-----head file of users
#include "../common/color.h"

#ifdef _D
#define DBG(frm, arg...) {\
    printf("[%s : %s : %d]", __FILE__, __func__ ,__LINE__);\
    printf(frm, ##arg);\
}
#else
#define DBG(frm, arg...)
#endif




#endif



