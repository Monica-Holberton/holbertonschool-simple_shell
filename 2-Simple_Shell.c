#include "holberton.h"

void __attribute__ ((constructor)) premain()
{
	printf("$ ");
}
/**
 * main - Simple UNIX shell (Task 2)
 * Return: 0 on success, 1 on error
*/

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
	 char **argv;
	 int i = 0;
	 char *path;
	 char *command;
	 int status;

	 /* Read lines until EOF (Ctrl+D) */
	 
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	{
		
		printf("intput: %li chacaters\n", read);
		if (lptr[read-1] == '\n')
		{
			lptr[read-1] = '\0';
			//printf("replaced n with \\0\n");
		}
		argv = split(lptr, ":");
		command = argv[0];
		path = _which(command);
		if (path != NULL)
		{
			
			execute_builtin(path, argv);
			//printf("bulit-in\n");
			

				
			
	 	}
		else
		{
			printf("Not built-in\n");
			exit(1);
		}

	}
	
	// exit() command not found
 	//printf("Line 39\n");
	 free(lptr);
	printf("\n");
	return (0);
} 