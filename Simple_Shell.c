#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1); /* Print newline on Ctrl+D */
				free(line);
				exit(0);
			}
			else
			{
				perror("getline failed");
				free(line);
				exit(EXIT_FAILURE);
			}
		}

		/* Remove newline character */
		line[strcspn(line, "\n")] = '\0';

		/* Split input into arguments */
		args = split_string(line);

		/* Execute command if input is not empty */
		if (args[0] != NULL)
			execute_command(args);

		free(args);
	}

	free(line);
	return (0);
}
