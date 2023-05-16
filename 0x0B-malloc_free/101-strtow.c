#include "main.h"
#include <stdlib.h>
/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int i, c, w;

	i = 0;
	w = 0;

	for (c = 0; str[c] != '\0'; c++)
	{
		if (str[c] == ' ')
			i = 0;
		else if (i == 0)
		{
			i = 1;
			w++;
		}
	}
	return (w);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, j = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_words(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[j] = tmp - c;
				j++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[j] = NULL;

	return (matrix);
}
