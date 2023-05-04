#include "main.h"
/**
 * reverse_array - reverses array of integers
 * @a: is the array
 * @n: is the number of elements of array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int c;
	int d;

	for (c = 0; c < n--; c++)
	{
		d = a[c];
		a[c] = a[n];
		a[n] = d;
	}
}
