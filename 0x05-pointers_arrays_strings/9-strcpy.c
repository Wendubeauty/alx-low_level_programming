#include "main.h"
/**
 * _strcpy - copies the string pointed to by src
 * @dest: points to the buffer where the string is copied from
 * @src: points to the string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
