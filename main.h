#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define _min(x, y) (((x) < (y)) ? (x) : (y))

typedef struct {
    char *command_name;
    void (*func)(char **command);
} function_map;

extern char **environ;
extern char **g_commands;
extern char *g_line;
extern char *g_shell_name;
extern int g_status;

char **tokenizer(char *input_string, char *delim);
void print(char *string, int stream);
void remove_newline(char *str);
void _strcpy(char *source, char *dest);
int _strlen(char *string);
int _strcmp(char *first, char *second);
char *_strcat(char *destination, char *source);
int _strspn(char *str1, char *str2);
int _strcspn(char *str1, char *str2);
char *_strchr(char *s, char c);
char *_strtok_r(char *string, char *delim, char **save_ptr);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int signum);
void remove_comment(char *input);
void env(char **tokenized_command);
void quit(char **tokenized_command);
void initializer(char **current_command, int type_command);
void non_interactive(void);
int parse_command(char *command);
void execute_command(char **tokenized_command, int command_type);
char *check_path(char *command);
void (*get_func(char *command))(char **);
char *_getenv(char *name);
#endif

