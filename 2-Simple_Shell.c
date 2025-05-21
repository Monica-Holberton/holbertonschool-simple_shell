#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	 char *argv[2];
	 int status;

	 /* Read lines until EOF (Ctrl+D) */
	 while (1){

		read = getline(&lptr, &len, stdin) != -1;
		printf("Line 32\n");
		pid_t pid = fork();
		if (pid == 0)
		{
			argv[0] = lptr;
			if (len != 0)
			{
				if (execve(argv[0], argv, NULL) != -1)
				{
					printf("place 1\n");
					printf("$ ");

				}

				else
				{
					printf("No command entered\n");/*EXIT*/
					exit(1);
				}
			}
			else {
				printf("out\n");
				exit(1);

			}
	 	}
		/*--------------------------------------------------------------------------------*/

	    else
        {
            wait(&status);
		}
    }

    free(lptr);
    printf("\n");
    return (0);
}