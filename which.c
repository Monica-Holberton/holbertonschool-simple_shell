
#include "holberton.h"


char * _which(char * filename)
{
int i;
int len;
struct stat st;
char *path = getenv("PATH");
    //filename=ls
char **dir = split(path, ":");
len = sizeof(dir);
char* paths[len];

for (i = 0; i<len-1; i++)
{
    int l = strlen(dir[i]);  
  
    // Add the new character at the end
    dir[i][l] = '/';
  
    // Add the null terminator
    dir[i][l + 1] = '\0';
    paths[i]=strcat(dir[i],filename);
    
}

i=0;
while (paths[i])
    {
        printf("%s:", paths[i]);
        if (stat(paths[i], &st) == 0)
        {
            printf(" FOUND\n");
            return paths[i];
        }
        else
        {
            printf("Not correct \n");
            
        }
        i++;
    }
    return NULL;
}
int main(void)
{
    _which("ls");
}