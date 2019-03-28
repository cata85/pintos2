#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include "threads/synch.h"

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

struct process_file { 
  int file_index;
  struct file *file;
  struct list_elem elem;
};

int process_add_file(struct file *f);

struct file* process_get_file(int file_index);

void process_close_file(int file_index);

/* Struct to keep track of child process */
struct child_process
{
  int pid;

  int load_status;
  struct semaphore load_status_sema;

  bool parent_waiting;
  struct lock parent_waiting_lock;

  bool exit;
  struct semaphore exit_sema;

  int status;

  struct list_elem elem; 
};

struct child_process* add_child_process (int pid);

struct child_process* get_child_process (int pid);

void remove_child_process (struct child_process *cp);

void remove_child_processes (void);





#endif /* userprog/process.h */
