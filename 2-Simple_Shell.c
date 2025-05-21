#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>      /* For perror */
#include <sys/types.h>  /* For pid_t */
#include <sys/wait.h>   /* For wait */

/**
 * main - A very simple UNIX command line interpreter
 *
 * Description:
 * - Displays a prompt ($)
 * - Reads a command (one word only)
 * - Executes it using execve
 * - Prints an error if the command doesn't exist
 * - Repeats until Ctrl+D (EOF)
 *
 * Return: Always 0
 */
int main(void)
{
    char *lptr = NULL;  
    size_t len = 0;   
    ssize_t read;    
    char *argv[2];    
    int status;          /* Status from wait */
    pid_t pid;           /* Process ID from fork */
	/*extern char **environ;*/

/* Infinite loop until EOF */
    while (1)  
    {
        printf("$ ");

        read = getline(&lptr, &len, stdin); /* Read user input line */
        if (read == -1)   /* If EOF (Ctrl+D) or error, exit loop */
            break;
		
        /* Prepare argv for execve: command is first argument, NULL */
        argv[0] = lptr;
        argv[1] = NULL;

        pid = fork();  /* Create a child process */

        if (pid == -1)  /* Fork failed */
        {
            printf("Fork Failed\n");
			exit(1);  /* Exit the program if fork fails */
        }

        if (pid == 0 && read>1)  /* Child process */
        {
			argv[0] = lptr;
            // i should exit here
            /* Attempt to execute the command */
        if (execve(argv[0], argv, NULL) == -1)
            {
                printf("ERROR\n");  /* Print error if execve fails */
				/*perror("execve");*/
				exit(1); /* inside the child process, Exit when fail */
				        /* if the command doesn’t exist or isn't executable*/
		    }
        }
        else  /* Parent process */
        {
            wait(&status);  /* Wait for the child process to finish */
			// if I reach here with no process I should exit 
			
			printf("\n");
        }
    }

    free(lptr);   /* Free the buffer */
    printf("\n"); /* Clean newline on exit after Ctrl+D */
    return (0);
}
