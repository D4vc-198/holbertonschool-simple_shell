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

typedef struct list{

	char *var;
	struct list *next;

} list_t;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*_getline*/
size_t _getline(char **str);
/*prompt*/
int prompt(char **env);
/*_strtok*/
char **_strtok(char *str, char *delm);
/*_strcat*/
char *_strcat(char *dest, char *src);
/*_strdup*/
char *_strdup(char *str);
/*_strcmp*/ 
int _strcmp(char *s1, char *s2);
/*_which*/
char *_which(char *str, list_t *env);
/*_exit*/
void __exit(char **s);
/*_execve*/
int _execve(char *argv[], list_t *env);
/*_env*/
int _env(char **str, list_t *env);
/*_strcpy.c*/
char *_strcpy(char *dest, char *src);
/*path*/
char *path(char *str, char **env);

char *get_env(char *str, list_t *env);
void _cd(char **str, list_t *env);
int built_in(char **token, list_t *env);
void non_interactive(list_t *env);
char *ignore_space(char *str);
char **c_strtok(char *str, char *delm);
int t_strlen(char *str, int pos, char delm);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);

#endif
