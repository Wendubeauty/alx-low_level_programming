#include "main.h"
/**
 * print_rev - This function prints in reverse
 * @s: is the string
 * Return: always 0 (success)
 */
void print_rev(char *s)
{
	int longi = 0;
	int n;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	s--;
	for (n = longi; n > 0; n--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
