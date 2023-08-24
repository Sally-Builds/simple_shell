#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

char *read_input();
char **split_command(char *buffer);
int get_len_of_argv(char *buff_dup, char *delim);
void run_sh(char **argv);
void exec_cmd(char **argv);
void free_argv(char **argv);

#endif

