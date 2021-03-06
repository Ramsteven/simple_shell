#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h> /* borrar despues */
#include <signal.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;

/*manage error*/
void manage_err(char *cont_array, ssize_t nread, int count_procces, char *av);

/*check commnad*/
void handler(int num);
void prompt(void);
void check_stat(char **array, ssize_t nread, int *stat_status, char *av);
ssize_t check_get_line(char **array, int *stat_status, char *av);


/*auxiliar functions*/
ssize_t length(char *size);
char *_strcat(char *dest, char *src);
int _strcmp(char *a, char *b);
char *_itoa(int num, char *strnum);
char *_strcpy(char *dest, char *src);

/*auxiliar functions2*/
void fix_token(char *token);
void *_calloc(unsigned int nmemb, unsigned int size);
void chek_isatty(int check_line);
void _exit_built(char *array_0, char *buffer, int *stat_status);
void find_path(char **array, ssize_t *nread, bool *x);
bool call_built_in(char **array, int *stat_status, char *buffer);

/* inicialization functions */
void ini_s(size_t *bytes, struct stat *st, ssize_t *nread, ssize_t *resta);
void check_o(int i, int check_line, const char *delim, bool x);


/*which*/
void functionToken_which(char *dest, char **pathDivision);
char *_strcpy_which_path(char *dest, char *src);
char *_which(char **array);



#endif
