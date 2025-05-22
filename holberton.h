#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Macros */
#define PROMPT "$ "
#define MAX_ARGS 2

/* Function Prototypes */

int is_input(char *command);  /* Returns True or False */

/* Prints the shell prompt ($) */
void print_prompt(void);

/* Reads command from standard input */
ssize_t read_command(char **lineptr, size_t *n);

/* Creates a child process to run a command */
int execute(char *argv[]);

/* Tokeniz the input line into arguments */
void tokenize_command(char *line, char *argv);

/* Checks if a command is a built-in */
int is_builtin(char *command);  /* Returns True or False */

/* Fork and Executes a built-in command */
int execute_builtin(char *command);

/* Execute command */
int execute(char *argv[]);

/*Checks if the string is found in the Global Variable */
bool in_path(char *string);

/*Find a path */
char *_which(const char *filename);


#endif /* HOLBERTON_H */