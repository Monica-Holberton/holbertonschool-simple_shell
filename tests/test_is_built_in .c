#include "../holberton.h"

int main(void)
{
    char *command; 
    //*command = "ls" >> known built in command
    //*coammnd = "ahsg" >> not a command
    // *command = " "; >> empty input
    //*command  = NULL >> NO input
    bool test = is_built_in(command);
    if (test)
    {
        printf("built-in\n");
    }
    else
    {
        printf("Not built-in");
    }
}