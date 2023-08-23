#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void run_shell(char **argv);
void execute_command(char **argv);
int total_len_of_string(char *s, char *delim);
void store_token_in_array(char **argv, char *s, char *delim);
char *_getenv(char *name);
#endif

