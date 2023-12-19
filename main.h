#ifndef HEADER_H
#define HEADER_H
#define TOKEN_DELIMITER " \t\n"
#define SIZE 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

char *line_interpreter(void);
char **line_parser(char *, const char *);
int command_executor(char **, char *);
void env_variables_printer(void);
char *path_checker(char *);
void free_double_pointer(char **);

#endif
