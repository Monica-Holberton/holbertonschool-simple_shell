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

/* Starts the shell loop */
void start_shell(void);

/* Checks if shell is running interactively */
int is_interactive(void);

/* Prints the shell prompt ($) */
void print_prompt(void);

/* Reads command from standard input */
ssize_t read_command(char **lineptr, size_t *n);


#endif /* HOLBERTON_H */