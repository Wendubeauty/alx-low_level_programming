#include "main.h"
/**
 * _puts - it prints a string, followed by a new line
 * @str: is the  string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
