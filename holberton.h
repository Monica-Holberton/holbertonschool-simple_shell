#ifndef HOLBERTON_H
#define HOLBERTON_H

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