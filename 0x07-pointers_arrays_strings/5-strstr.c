#include "main.h"
/**
 * _strstr - finds the first occurrence of a substring in a string
 * @haystack: the string to search in
 * @needle: the substring to search fo
 * Return: a pointer to the beginning of the located substring
 * or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;

		while (*n == *haystack && *n != '\0' && *haystack != '\0')
		{
			haystack++;
			n++;
		}

		if (*n == '\0')
			return (h);

		haystack = h + 1;
	}

	return (NULL);
}

