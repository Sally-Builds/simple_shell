#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>

#define PATH_COMMAND 3

#define _min(x, y) (((x) < (y)) ? (x) : (y))
#define INVALID_COMMAND -1

typedef struct {
    char *command_name;
    void (*func)(char **command);
} function_map;

#define INTERNAL_COMMAND 2
extern char **environ;
extern char *g_shell_name;
extern int g_status;


void print(char *string, int stream);
void remove_newline(char *str);
void _strcpy(char *source, char *dest);
int _strcmp(char *first, char *second);
char *_strcat(char *destination, char *source);
int _strspn(char *str1, char *str2);
int _strlen(char *string);
char **get_token(char *input_string, char *delim);
int _strcspn(char *str1, char *str2);
char *_strtok_r(char *string, char *delim, char **save_ptr);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int signum);
void env(char **tokenized_command);
void quit(char **tokenized_command);
void create_child(char **current_command, int type_command);
void non_interactive(void);
void remove_comment(char *input);
char *_strchr(char *s, char c);

int parse_command(char *command);
void execute_command(char **tokenized_command, int command_type);
char *check_path(char *command);
void (*run_function(char *command))(char **);
char *_getenv(char *name);

extern char *g_line;
extern char **g_commands;
#define EXTERNAL_COMMAND 1
#endif

