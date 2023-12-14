#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUILTIN {"exit", "env", "setenv", "cd", "unsetenv", NULL}
#define BUFF_SIZE 1024

void prompt(void);

char *get_input(void);

char **seperate_commands(char *buff);

char *get_path_command(char *command);

char *_getenv(const char *name);

int execute(char **commands, char **av, int idx);

void free_arr(char **arr);

/* builtins_check */
int is_builtin(char *command);
void find_builtin(char **commands, char **av, int *status, int index);

/* builtins_fcts */
void exit_shell(char **commands, char **av,  int *status, int idx);
void print_environment(char **commands, int *status);
void set_env(char **commands, char **av,  int *status, int idx);
void unset_env(char **commands, char **av,  int *status, int idx);

/* string manipulation */
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
void reverse_str(char *str, int len);

/* print fcts */
void printerr(char *name, char *command, int idx);
void _puts(char *str);
int _putchar(char c);

/* handle ints */
int _atoi(char *s);
int is_digit(char *str);
char *_itoa(int n);

extern char **environ;

#endif /* MAIN_H */
