#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    /* Find the end of the destination string */
    while (*ptr != '\0')
        ptr++;

    /* Append the source string to the destination string */
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0'; /* Add null terminator */

    return dest;
}

