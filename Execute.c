#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

void execute_command(char **args)
{
    char *path_env = getenv("PATH");
    char *path_copy, *dir, *full_path;
    pid_t pid;
    int status;

    if (!args[0])
        return;

    /* If command has a slash, try to execute directly */
    if (strchr(args[0], '/'))
    {
        execve(args[0], args, environ);
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    path_copy = strdup(path_env); /* Important! */
    if (!path_copy)
    {
        perror("strdup");
        return;
    }

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        full_path = malloc(strlen(dir) + strlen(args[0]) + 2);
        if (!full_path)
        {
            perror("malloc");
            free(path_copy);
            return;
        }

        sprintf(full_path, "%s/%s", dir, args[0]);

        if (access(full_path, X_OK) == 0)
        {
            pid = fork();
            if (pid == 0)
            {
                execve(full_path, args, environ);
                perror("ERROR");
                exit(EXIT_FAILURE);
            }
            else if (pid > 0)
            {
                waitpid(pid, &status, 0);
                free(full_path);
                free(path_copy);
                return;
            }
            else
            {
                perror("fork");
                free(full_path);
                free(path_copy);
                return;
            }
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

	write(STDERR_FILENO, "ERROR! Command Not Found.\n", 27);
    free(path_copy);
}
