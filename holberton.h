#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

#include <errno.h>      /* For perror */
#include <sys/types.h>  /* For pid_t */
#include <sys/wait.h>
#include <sys/stat.h>
typedef struct stat st;
typedef struct node
{
    char *str;
    struct node* next;
}node;

char** split(char *string, char *delimiter);
node* append(node *head , char *string);
node* get_path(char **path);
bool is_built_in(char *command);


int is_input(char *command);  /* Returns True or False */

/* Prints the shell prompt ($) */
void print_prompt(void);

/* Reads command from standard input */
ssize_t read_command(char **lineptr, size_t *n);

/* Creates a child process to run a command */
int execute(char *argv[]);

/* Tokeniz the input line into arguments */
void tokenize_command(char *line, char *argv);

/* Fork and Executes a built-in command */
int execute_builtin(char *command);


/*Checks if the string is found in the Global Variable */
bool in_path(char *string);

/*Find a path */
char *_which(char *filename);

void env(void);
int _atoi(char *string);
#endif /* HOLBERTON_H */

