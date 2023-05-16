#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of a string
 *            which consists entirely of characters from another string.
 * @s: Pointer to the string to be scanned.
 * @accept: Pointer to the string containing the characters to match.
 *
 * Return: The number of characters in the initial segment of @s that match
 *         any character from @accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int i, j;
    int match;

    for (i = 0; s[i] != '\0'; i++)
    {
        match = 0;
        for (j = 0; accept[j] != '\0'; j++)
        {
            if (s[i] == accept[j])
            {
                match = 1;
                break;
            }
        }

        if (match == 0)
            break;

        count++;
    }

    return count;
}

