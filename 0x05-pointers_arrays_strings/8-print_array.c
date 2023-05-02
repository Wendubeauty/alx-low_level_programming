#include "main.h"
/**
 * print_array - pints n elements of an array
 * @a: is the array
 * @n: is the number of elements to be printed
 * Return: a and n inputs
 */
void print_array(int *a, int n)
{
	int m;

	for (m = 0; m < n; m++)
	{
		printf("%d", a[m]);
		if (m < n - 1)
			printf(", ");
	}
	printf("\n");
}
