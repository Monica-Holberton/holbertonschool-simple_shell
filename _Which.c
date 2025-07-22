#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * _which - Searches for a command in the directories of PATH using stat
 * @filename: Name of the command like (ls)
 *
 * Return: Full path if found, NULL if not.
 */
char *_which(const char *filename)
{
    static char full_path[1024];            /* Buffer to store the full path */
    const char *path = getenv("PATH");      /* Get the PATH environment variable */
    const char *start = path, *end;         /* Pointers to parse each directory */
    struct stat st;                         /* To store file info for stat() */

/* If input or PATH is missing, return NULL */
    if (!filename || !path)
        return (NULL);

    /* Loop in each directory in PATH */
    while (*start)
    {
        end = strchr(start, ':');    /* Find the next ':' (end of current dir) */
        if (!end)
            end = start + strlen(start);  /* Last directory */

        size_t len = end - start;
        /* Construct full path: directory + '/' + filename */
        snprintf(full_path, sizeof(full_path), "%.*s/%s", (int)len, start, filename);

        /* Check if file exists at this full path */
        if (stat(full_path, &st) == 0)
            return (full_path);  /* File found, return its full path */

        if (*end == '\0')
            break;   /* End of PATH string, break the loop */

        start = end + 1;  /* Move to the next directory */
    }

    return (NULL);   /* File not found in any PATH directory */
}
