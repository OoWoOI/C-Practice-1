/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 03:26:15 PM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

//head file of sys
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#include<sys/sem.h>
#include<pthread.h>
#include<sys/msg.h>


//head file of user
#include "common.h"
#include "my_popen.h"
#include "thread_pool.h"


#endif
