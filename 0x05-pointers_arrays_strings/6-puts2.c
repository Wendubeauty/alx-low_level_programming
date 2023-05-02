#include "main.h"
/**
 * puts2 - prints only one character out of two
 * @str: is the input string
 * Return: print
 */
void puts2(char *str)
{
	int longi = 0;
	int n = 0;
	char *y = str;
	int l;

	while (*y != '\0')
	{
		y++;
		longi++;
	}
	n = longi - 1;
	for (l = 0; l <= n; l++)
	{
		if (l % 2 == 0)
		{
			_putchar(str[l]);
		}
	}
	_putchar('\n');
}
