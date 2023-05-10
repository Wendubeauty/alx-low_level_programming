#include "main.h"
/**
 * _sqrt_recursion_helper - finds the natural square root of a number
 * @n: the number to find the square root of
 * @i: the candidate square root to check
 * Return: the natural square root of n if it exists, otherwise -1
 */
int _sqrt_recursion_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	else if (i * i == n)
		return (i);
	else
		return (_sqrt_recursion_helper(n, i + 1));
}

/**
 * _sqrt_recursion - finds the natural square root of a number
 * @n: the number to find the square root of
 * Return: the natural square root of n if it exists, otherwise -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else
		return (_sqrt_recursion_helper(n, 0));
}
