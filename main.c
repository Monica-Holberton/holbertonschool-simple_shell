#include "holberton.h"

/**
 * main - Simple shell loop
 * Return: Always 0
 */
int main(void)
{
    char *input = "ls -l /";
    char **args = split_string(input);

    for (int i = 0; args[i]; i++)
        printf("arg[%d] = %s\n", i, args[i]);

    return 0;
}
