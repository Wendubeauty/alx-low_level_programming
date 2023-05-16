#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: an array of strings containing the arguments
 * Return: a pointer to a new string containing the concatenated arguments,
 * or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, len, total_len = 0;
	int index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
			len++;

		total_len += len + 1;
	}

	str = malloc(sizeof(char) * total_len + 1);

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			str[index] = av[i][len];
			len++;
			index++;
		}
		str[index] = '\n';
		index++;
	}

	str[index] = '\0';
	return (str);
}
