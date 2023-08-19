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

/**prototypes*/
void prompt(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memcpy(void *dest, void *src, size_t n);
char **get_token(char *buff);
char **resize_buff(char **buff, unsigned int old_size);
ssize_t readline(char **buff, size_t *n);
int _strlen_recursion(char *s);
int executor(char *tokens[]);
extern char **environ;
#endif
