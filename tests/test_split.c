#include "../holberton.h"

int main(void)
{
    
    //char s[] = "This is a test"; 
    //char s[] = "test";
    //char s[] = " ";
    // char s[] = NULL;
    char *delm = " ";
    char ** test  = split(s, delm); 
    for (int i  = 0; test[i] != NULL; i++)
    {
        printf("%s\n", test[i]);
    }
}