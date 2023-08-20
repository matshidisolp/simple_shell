#ifndef MAIN_H
#define MAIN_H

/**libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/*global variables*/
extern char **environ;

/*structures*/
/**
  * struct stat - stores info about a a file
  * Description: stores info about a file
*/
struct stat info;
/**prototypes*/
void prompt(void);
char *_strdup(const char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
void *_memcpy(void *dest, void *src, size_t n);
char **get_token(char *buff, char *delim);
char **resize_buff(char **buff, unsigned int old_size);
ssize_t readline(char **buff, size_t *n);
int _strlen_recursion(const char *s);
void lunch(char **arg);
int find_path(char *cmd);
int if_path(char *cmd);
char *build_path(char *cmd);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int _strlen_recursion(const char *s);
int executor(char *tokens[]);
void handle_exit(char *tokens[]);
#endif
