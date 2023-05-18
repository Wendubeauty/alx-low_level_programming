#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes from s2 to concatenate
 * Return: Pointer to the newly allocated concatenated string
 * NULL if the function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len = 0, s2_len = 0, concat_len = 0;
	char *concat_str, *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[s1_len] != '\0')
		s1_len++;

	while (s2[s2_len] != '\0')
		s2_len++;

	if (n >= s2_len)
		n = s2_len;

	concat_len = s1_len + n;

	concat_str = malloc(sizeof(char) * (concat_len + 1));

	if (concat_str == NULL)
		return (NULL);

	ptr = concat_str;

	while (*s1 != '\0')
		*ptr++ = *s1++;

	while (n > 0)
	{
		*ptr++ = *s2++;
		n--;
	}

	*ptr = '\0';

	return (concat_str);
}
