#include "main.h"

/**
 * _memset - Fills a block of memory with a specified value.
 * @s: Pointer to the memory block to be filled.
 * @b: Value to be set.
 * @n: Number of bytes to be set.
 *
 * Return: A pointer to the memory block.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;

    return s;
}

