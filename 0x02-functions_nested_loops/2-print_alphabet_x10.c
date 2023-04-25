#include "main.h"
/**
 * print_alphabet_x10 - Prints ten times the alphabet in lowercase
 * Return void
 */
void print_alphabet_x10(void)
{
	char ch;
	int n;

	n = 0;

	while (n < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		n++;
	}
}
