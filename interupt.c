#include "holberton.h"

void handle_interupt(int sig)
{
    write(1, "$", 1);
}

int main(void){
    signal(SIGINT, handle_interupt);
    return 0;
}