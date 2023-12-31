#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

extern char **environ;
extern int sig_flag;

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char **parse_data(char *str);
void free_toks(char **toks);
char *get_env(char *name);
char *find_path(char *cmd);
void exec_input(char **toks);
char *_strdup(char *str);
void _sigint(int sig_flag);
void shell_exit(void);

#endif /* MAIN_H */
