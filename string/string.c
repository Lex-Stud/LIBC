// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <unistd.h>

char *strcpy(char *destination, const char *source)
{
    char *aux = destination;

    while (*source != '\0')
    {
        *aux = *source;
        aux++;
        source++;
    }
    *aux = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    char *aux = destination;

    while (*source != '\0' && len > 0)
    {
        *aux = *source;
        aux++;
        source++;
        len--;
    }

    while (len > 0)
    {
        *aux = '\0';
        aux++;
        len--;
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
    while (*destination != '\0')
        destination++;

    strcpy(destination, source);

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    while (*destination != '\0')
        destination++;

    while (*source != '\0' && len > 0)
    {
        *destination = *source;
        destination++;
        source++;
        len--;
    }
    *destination = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 < *str2)
            return -1;
        else if (*str1 > *str2)
            return 1;
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    else if (*str1 == '\0')
        return -1;
    else if (*str2 == '\0')
        return 1;

    return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    while (*str1 != '\0' && *str2 != '\0' && len > 0)
    {
        if (*str1 < *str2)
            return -1;
        else if (*str1 > *str2)
            return 1;
        len--;
        str1++;
        str2++;
    }
    if (len == 0)
        return 0;
    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    else if (*str1 == '\0')
        return -1;
    else if (*str2 == '\0')
        return 1;

    return -1;
}

size_t strlen(const char *str)
{
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return (char *)str;

        str++;
    }

    return NULL;
}

char *strrchr(const char *str, int c)
{
    char *aparitie = NULL;

    while (*str != '\0')
    {
        if (*str == c)
            aparitie = (char *)str;
        str++;
    }

    return aparitie;
}

char *strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
        return (char *)haystack;

    while (*haystack != '\0')
    {
        char *hay = (char *)haystack;
        char *arya = (char *)needle;

        while ((*hay != '\0' && *arya != '\0') && (*hay == *arya))
        {
            hay++;
            arya++;
        }

        if (*arya == '\0')
            return (char *)haystack;

        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    char *stark = NULL;

    if (*needle == '\0')
        return (char *)haystack;

    while (*haystack != '\0')
    {
        char *hay = (char *)haystack;
        char *arya = (char *)needle;

        while ((*hay != '\0' && *arya != '\0') && (*hay == *arya))
        {
            hay++;
            arya++;
        }

        if (*arya == '\0')
            stark = (char *)haystack;

        haystack++;
    }

    return stark;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    char *sor = (char *)source;
    size_t i;

    for (i = 0; i < num; i++)
        dest[i] = sor[i];

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    char *sor = (char *)source;

    if (dest < sor)
    {
        for (size_t i = 0; i < num; i++)
            dest[i] = sor[i];
    } else {
        for (size_t i = num; i > 0; i--)
            dest[i - 1] = sor[i - 1];
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    char *p1 = (char *)ptr1;
    char *p2 = (char *)ptr2;
    size_t i;

    for (i = 0; i < num; i++)
    {
        if (p1[i] < p2[i])
            return -1;
        if (p1[i] > p2[i])
            return 1;
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    char *aux = (char *)source;
    size_t i;
    for (i = 0; i < num; i++, aux++)
        *aux = (char)value;
    return source;
}
