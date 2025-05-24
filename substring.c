#include "holberton.h"
char** split(char *string, char *delimiter)
{
    int counter,i;
    counter = 0;
    char **sub_strings = NULL;
    char *string_copy;
    char *token;
    string_copy = strdup(string);
    token = strtok(string_copy, delimiter);
    while (token != NULL)
    {
        counter++;
        token = strtok(NULL, delimiter);
    }
    free(string_copy);
    if (counter == 0)
    {
        return (NULL);
    }
    sub_strings = malloc((counter * sizeof(char *)) + 1);
    if (sub_strings == NULL)
    {
        return (NULL);
    }
    i = 0;
    token  = strtok(string, delimiter);
    while (token != NULL)
    {
        sub_strings[i] = malloc(sizeof(strlen(token) + 1));
        if (sub_strings[i] == NULL)
        {
            return (NULL);
        }
        strcpy(sub_strings[i], token);
        i++;
        token = strtok(NULL, delimiter);
    }
    sub_strings[counter] = NULL;
    return (sub_strings);
}