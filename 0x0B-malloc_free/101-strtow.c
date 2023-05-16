#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int i, count = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
		}
		else
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, word_count = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
		}
		else
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
				j++;

			words[k] = malloc((j - i + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				while (k > 0)
					free(words[--k]);
				free(words);
				return (NULL);
			}
			j = 0;
			while (str[i] != ' ' && str[i] != '\0')
				words[k][j++] = str[i++];
			words[k++][j] = '\0';
		}
	}
	words[k] = NULL;
	return (words);
}
