
#include "holberton.h"


char * _which(char * filename)
{
    printf("_which %s\n",filename);
 st t;
int len, i;
char *path = getenv("PATH");
    //filename=ls
char **dir = split(path, ":");
for (len = 0; dir[len]; len++);
char **paths = malloc(sizeof(char *) * len);
printf("%s\n", path);
printf("len : %i\n", len);
for (i = 0; i<len; i++)
{
    int l = strlen(dir[i]);

    // Add the new character at the end
    dir[i][l] = '/';

    // Add the null terminator
    dir[i][l + 1] = '\0';
    paths[i]=strcat(dir[i],filename);
    printf(" L26: %s\n", paths[i]);
}

i=0;
while (paths[i])
    {
        printf("L32: %s:", paths[i]);
        if (stat(paths[i], &t) == 0)
        {
            //printf(" FOUND\n");
            return paths[i];
        }
        i++;
    }
    for (int j = 0; j < len; j++) {
    free(paths[j]);
}
free(paths);
    //printf("NOT FOUND\n");
    return NULL;
}
