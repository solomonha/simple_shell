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
#include <errno.h>
#include<fcntl.h>



extern char **environ;

/**
 * struct data - programs data
 * @name: the name of the executble
 * @input: input to be read by getline
 * @command: the first command typed by the user
 * @exec_counter: number of executed commands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens : pointer to array of tokinized inputs
 * @env: copy of enviroment
 * @alias_list: array of pointers with aliases
 *
 */
typedef struct data
{
	char *input;
	int exec_counter;
	int file_descriptor;
	char **env;
	char *command;
	char **tokens;
	char **alias_list;
	char *name;
} data;

/**
 * struct builtin - list of builtins
 * @name: the name of the builtin command
 * @f: function pointer used to call and execute
 * the command's function
 */

typedef struct builtin
{
	char *name;
	int (*f)(void);
} builtin;


/* Read line function prototypes */
char *read_line(void);
int execute(char **args);
int execute_commands(char **args);
void print_prompt(void);

int shell_exit(void);
char *_strtok(char *string, char *delim);
int checker(char *array_command[], int i, char array_operators[]);
int _getline(data *d);
int shell_env(void);
int _strlen(char *string);
char *_strcpy(char *string);
int _strcmp(char *str1, char *str2, int num);

#endif
