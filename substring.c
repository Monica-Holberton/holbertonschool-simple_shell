#include "holberton.h"
char **split(char *string, char *delimiter)
{
    int counter = 0, i = 0;
    char **sub_strings = NULL;
    char *string_copy1 = strdup(string);
    char *string_copy2 = strdup(string);
    char *token;

    if (!string_copy1 || !string_copy2)
        return NULL;

    // First pass: count tokens
    token = strtok(string_copy1, delimiter);
    while (token != NULL)
    {
        counter++;
        token = strtok(NULL, delimiter);
    }
    free(string_copy1);

    if (counter == 0)
    {
        // must free before return
        free(string_copy2);
        return NULL;
    }

    // +1 for NULL terminator \0
    sub_strings = malloc((counter + 1) * sizeof(char *));
    if (sub_strings == NULL)
    {
        free(string_copy2);
        return NULL;
    }

    // Second pass: actually split and copy
    token = strtok(string_copy2, delimiter);
    while (token != NULL)
    {
        sub_strings[i] = malloc(strlen(token) + 1); // strlen + \0
        if (sub_strings[i] == NULL)
        {
            return NULL;
        }
        strcpy(sub_strings[i], token);
        i++;
        token = strtok(NULL, delimiter);
    }
    sub_strings[i] = NULL;

    free(string_copy2);
    return (sub_strings);
}