#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: constant byte to be filled
 * @n: number of bytes to be filled
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;

	return (s);
}
