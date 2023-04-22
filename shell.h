#ifndef SHELL_H
#define SHELL_H

#define RL_BUFFER_SIZE 1024

/* LIBRARIES */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Read line function prototypes */
char *read_line(void);

#endif
