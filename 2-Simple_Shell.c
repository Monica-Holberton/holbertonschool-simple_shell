#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - A very simple UNIX command line interpreter
 *
 * Description:
 * - Displays a prompt ($)
 * - Reads a command (one word only)
 * - Executes it using execve
 * - Print an error if the command doesn't exist
 * - Repeats until Ctrl+D (EOF)
 *
 * Return: Always 0
 */

 void __attribute__ ((constructor)) premain()
 {
	 printf("$ ");
 }
 int main(void)
 {
	 char *lptr = NULL;
	 size_t len = 0;
	 ssize_t read;
	 char *argv;

	 /* Read lines until EOF (Ctrl+D) */
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	 {
		printf("Line 32\n");
		pid_t pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("Line 34\n");
				printf("$ ");
				perror("ERRor");
			}
			else
			{
				printf("Line 42\n");
			}
	 	}
	}
 printf("Line 39\n");
	 free(lptr);
	 printf("\n"); /* Clean newline after Ctrl+D */
	 return (0);
 }
