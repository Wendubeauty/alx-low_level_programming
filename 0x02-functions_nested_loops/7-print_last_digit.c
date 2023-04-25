#include "main.h"
/**
 * print_last_digit - Prints the last digit of a number
 * @n: the int to extract the last digit from
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int d;	

	if (n < 0)
		n = -n;

	d = n % 10;
		
	if (d < 0)
		d = -d;
	
	_putchar(d + '0');
	
	return (d);
		
}
