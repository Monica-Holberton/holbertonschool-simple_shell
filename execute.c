#include "main.h"
#include <unistd.h>

int execute(char *argv[])
{
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
        return (-1);
    }
    return (0);
}