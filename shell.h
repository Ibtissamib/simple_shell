#ifndef SHELL_H
#define SHELL_H

/*Included Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>



/*Function Prototypes*/
void sh_cmd(char *line, ssize_t n);
int exit_handler(char *userinputs, ssize_t nlines);
int _strcmp(char *s1, char *s2);
char *_delim(char *userinput, ssize_t nlines);
ssize_t _strlen(char *s);
char *_strdup(char *str);
int nbr_wrd(char *str, ssize_t nlines);
char *_getenv(const char *name);
char *str_concat(char *s1, char *s2);
void _path_handler(char *userinput, ssize_t nlines);
ssize_t _getline(char **line, size_t *len, FILE *stream);
int call_fork(char *userinput, ssize_t nlines);


/*Data Structures*/
extern char **environ;


#endif /*End of SHELL Header*/
