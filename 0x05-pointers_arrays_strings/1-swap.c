#include "main.h"
/**
 * swap - This function swaps the values of two integers
 * @a: is the first integer to swap
 * @b: is the second integer to swap
 */
void swap_int(int *a, int *b)
{
	int n;

	n = *a;
	*a = *b;
	*b = n;
}
