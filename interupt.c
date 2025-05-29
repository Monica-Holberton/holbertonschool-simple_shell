#include "holberton.h"

void handle_interupt(int sig)
{
    write(1, "$", 1);
}