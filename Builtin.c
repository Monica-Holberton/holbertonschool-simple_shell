#include "holberton.h"
#include <string.h>

/**
 * is_builtin - Checks if a command is a built-in shell command
 * @command: The command to check
 *
 * Return: 1 if it's built-in, 0 otherwise
 */
int is_builtin(const char *command)
{
    const char *builtins[] = {"exit", "env", "cd", "help", "ls", NULL};
    int i = 0;

    while (builtins[i])
    {
        if (strcmp(command, builtins[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}