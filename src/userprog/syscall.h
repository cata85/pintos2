#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "threads/synch.h"

#define CLOSE_ALL -1
#define ERROR -1

#define NOT_LOADED 0
#define LOAD_SUCCESS 1
#define LOAD_FAIL 2

// lock for accessing a file from system
struct lock sys_file_lock;


void syscall_init (void);

#endif /* userprog/syscall.h */
