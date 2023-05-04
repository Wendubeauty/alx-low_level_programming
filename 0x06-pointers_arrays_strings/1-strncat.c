#include "main.h"
/**
 * _strncat - this function concatenates two strings
 * @dest: is the input value
 * @src: is the input value
 * @n: is the input value
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int a;
	int m;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	m = 0;
	while (m < n && src[m] != '\0')
	{
		dest[a] = src[m];
		a++;
		m++;
	}
	dest[a] = '\0';
	return (dest);
}
