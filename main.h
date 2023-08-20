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
int set_argv(char *buffer, char**argv);

#endif

