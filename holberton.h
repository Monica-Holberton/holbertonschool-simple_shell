#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function Prototypes */

/* Splits a string into tokens based on a given delimiter */
char **split_string(char *str);

/* Checks if a command is a built-in (like "exit") */
int is_builtin(const char *command);

/* Executes a command using fork and execve */
int execute_command(char **args);

#endif /* HOLBERTON_H */

