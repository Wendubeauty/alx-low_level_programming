#include "main.h"

/**
 * _memcpy - Copies a block of memory from source to destination.
 * @dest: Pointer to the destination memory block.
 * @src: Pointer to the source memory block.
 * @n: Number of bytes to copy.
 *
 * Return: A pointer to the destination memory block.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];

    return dest;
}

