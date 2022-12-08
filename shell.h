#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*_getline*/
size_t _getline(char **str);
/*prompt*/
int prompt(int ac, char **av, char **env);
/*_strtok*/
char **_strtok(char *str, char *delm);
/*_strcat*/
char *_strcat(char *dest, char *src);
/*_strdup*/
char *_strdup(char *str);
/*_strcmp*/ 
int _strcmp(char *s1, char *s2);
/*_which*/
char *_which(char *str, char **env);
/*_exit*/
void __exit(char **s);
/*_execve*/
int _execve(char *argv[], char **env);
/*_env*/
int _env(char **str, char **env);
/*_strcpy.c*/
char *_strcpy(char *dest, char *src);
/*path*/
char *path(char *str, char **env);

char *get_env(char *str, char **env);
void _cd(char **str, char **env);
int built_in(char **token, char **env);
void non_interactive(char **env);
char *ignore_space(char *str);

#endif
