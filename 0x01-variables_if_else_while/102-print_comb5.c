#include <stdio.h>
/**
 * main - Entry point
 * Return: always 0 (success)
 */
int main(void)
{
	int n;
	int m;

	for (n = 0; n <= 99; n++)
	{
		for (m = n; m <= 99; m++)
		{
			if (n == m)
				continue;
			putchar(n / 10 + '0');
			putchar(n % 10 + '0');
			putchar(' ');
			putchar(m / 10 + '0');
			putchar(m % 10 + '0');

			if (n == 98 && m == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
