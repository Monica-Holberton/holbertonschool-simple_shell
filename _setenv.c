#include "holberton.h"



int _setenv(char *value, int overwrite)
{
   char *new_value;

   if (name == NULL || value == NULL){
    return (-1);
   }

   if(name != NULL && value != NULL){
    new_value = getenv(name);
    if (new_value == NULL){
        return -1;
        }
    //else if(setenv(name, value, overwrite) == 0){
        //return 0;
    }
    }
   }


