#include "holberton.h"



int _setenv(char *value, int overwrite)
{
    if(value == NULL){
        return -1;
    }

        name = value;
    if(overwrite == 1){
        return 0;
    }

}
