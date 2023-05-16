#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sign = 1; /* Default sign is positive */
    int result = 0;
    int i = 0;

    /* Check for sign */
    if (s[0] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert string to integer */
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            i++;
        }
        else
        {
            /* Stop conversion if non-digit character encountered */
            break;
        }
    }

    return sign * result;
}

