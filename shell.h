#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
char *getLine(void);
char **makeStrtok(char *string);
char *getPath(char *string);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(const char *s1, const char *s2);
char *navPath(char *string);
void *_realloc(void *ptr, unsigned int new_size);
#endif
