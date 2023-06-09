#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there is one or more chars in the
 *         string @b that is not 0 or 1, or if @b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	char c;

	if (b == NULL)
		return (0);

	while ((c = *b++) != '\0')
	{
		if (c == '0')
		{
			result = (result << 1) + 0;
		}
		else if (c == '1')
		{
			result = (result << 1) + 1;
		}
		else
		{
			/* Invalid character found, return 0 */
			return (0);
		}
	}

	return (result);
}

