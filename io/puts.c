#include <string.h>
#include <stdio.h>
#include <unistd.h>


void puts(const char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
