#include "../holberton.h"

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    // char argv[] = {"ls", "-l", "/usr/", NULL};
    // char argv[] = {"ls", "-l", NULL};
    // char argv[] = {"ls"};
    // char argv[] = {"/bin/ls"};
    int status = execute(argv);
    if(status == 0)
    {
        printf("Executed successfully\n");
    }
    if (status == 1)
    {
        printf("fork is not done!\n");
    }
    if (status == -1)
    {
        printf("Execution error\n");
    }
    return (0)
}