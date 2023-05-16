#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to copy.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i;

    /* Copy characters from source to destination up to n bytes 
     * or until end of source
     */
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    /* Fill remaining bytes of destination with null characters */
    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

