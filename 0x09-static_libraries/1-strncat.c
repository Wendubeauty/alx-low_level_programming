#include "main.h"

/**
 * _strncat - Concatenates two strings up to n bytes.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to concatenate.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *ptr = dest;

    /* Find the end of the destination string */
    while (*ptr != '\0')
        ptr++;

    /* Append the source string to the destination string, 
     * up to n bytes
     */
    while (*src != '\0' && n > 0)
    {
        *ptr = *src;
        ptr++;
        src++;
        n--;
    }

    *ptr = '\0'; /* Add null terminator */

    return dest;
}

