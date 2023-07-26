#ifndef SHELL_H
#define SHELL_H

/*Included Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/*Function Prototypes*/
void _exec_cmd(char *userinput, ssize_t n);
void _path_handler(char *userinput, ssize_t n);
int _strcmp(char *s1, char *s2);
ssize_t _strlen(char *s);
char *_strdup(char *str);
char *_decrem(char *b);
char *str_concat(char *s1, char *s2);
int nbr_wrd(char *str, ssize_t n);
char *_getenv(const char *name);
void _print_env(void);
ssize_t _getline(char **line, size_t *len, FILE *stream);
int call_fork(char *userinput, ssize_t n);



#endif /*End of SHELL Header*/
