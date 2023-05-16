#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string containing the bytes to match.
 *
 * Return: A pointer to the first occurrence in @s of any character from @accept,
 *         or NULL if no match is found.
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        char *curr_accept = accept;

        while (*curr_accept != '\0')
        {
            if (*s == *curr_accept)
                return s;

            curr_accept++;
        }

        s++;
    }

    return NULL;
}

