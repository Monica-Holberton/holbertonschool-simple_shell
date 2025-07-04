#include "holberton.h"


/**
 * main - Simple UNIX shell (Task 2)
 * Return: 0 on success, 1 on error
 */
int main(void)
{
    char *lptr = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[2];
    pid_t pid;
    int status;

 void __attribute__ ((constructor)) premain()
 {
	 printf("$ ");
 }
}
 int main(void)
 {
	/*
	* Check if in interactive mode
	* Check if the command is built-in
	* check if the command is "exit"
	* Try to execute the program
	*/

	 char *lptr = NULL;
	 size_t len = 0;
	 ssize_t read;
	 char *argv[64];
	 int i = 0;
	 int status;
	 char * path;

	 char *full_path;

	 /* Read lines until EOF (Ctrl+D) */
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	{

		//printf("intput: %li chacaters\n", read);
		if (lptr[read-1] == '\n')
		{
			lptr[read-1] = '\0';
			//printf("replaced n with \\0\n");
		}
		else if (is_built_in(lptr) == true)
		{
			//printf("bulit-in\n");
			char *command = split(lptr, " ")[0];
			printf("command : %s\n");
			/* Check if command is exit*/
			if (strcmp(command, "exit") == 0)
			{
				printf("exiting......\n");
				exit(-1);
			}
			else if(strcmp(command, "env") == 0)
			{
				env();
				exit(3);
			}
			else
			{
				/*my modif.*/
				char *full_path = _which(command);
				if (full_path)

					argv[0] = full_path;
					execute(argv);
				}

            	printf("%s: command not found\n");
        	}

				/*modif. end*/

				printf("$ ");
			}
		}



		else
		{
			printf("Not built-in\n");
			exit(1);
		}

	}
}
	// exit() command not found
 	//printf("Line 39\n");
	 free(lptr);
	printf("\n");
	return (0);
 }
