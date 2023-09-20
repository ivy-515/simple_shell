#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void x_prompt(void);
void x_signal(int signals);
void x_EOF(char *buffer);
void exit_shell(char **command);
void fork_cmd(char **command, char *name, char **env, int cicles);
int x_cd(const char *path);
void execute_cmd(char **command, char *name, char **env, int cicles);
void print_envirement(char **envi);
char **x_getPATH(char **env);
void print_nfound(char *name, int cicles, char **cmd);
char **split_cmd(char *buffer, const char *s);
void free_cmd(char **cmd);
void free_exit(char **cmd);
int x_strcmp(char *s1, char *s2);
unsigned int x_strlen(char *s);
char *x_strcpy(char *dest, char *src);
int x_atoi(char *s);
char *x_strcat(char *dest, char *src);
void x_str(char *str);
int token_len(char *str, char *delim);
int tokens_count(char *str, char *delim);
char **x_strtok(char *line, char *delim);

#endif /* _SHELL_H_ */

