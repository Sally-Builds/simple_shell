#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024

extern char **environ;

void handle_signal(int signum);
void tokenize_command(char *command, char *args[], int *num_args);
void execute_command(char *args[]);
void handle_built_in_commands(char *args[]);
void process_input();

#endif

