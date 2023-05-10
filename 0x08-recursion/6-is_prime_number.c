#include "main.h"
/**
 * is_divisible - check if n is divisible by divisor
 * @n: the number to check
 * @divisor: the divisor to check
 * Return: 1 if n is divisible by divisor, 0 otherwise
 */
int is_divisible(int n, int divisor)
{
	if (n % divisor == 0)
		return (1);
	else if (divisor * divisor > n)
		return (0);
	else
		return (is_divisible(n, divisor + 1));
}

/**
 * is_prime_number - check if n is a prime number
 * @n: the number to check
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else if (n == 2)
		return (1);
	else
		return (!is_divisible(n, 2));
}
