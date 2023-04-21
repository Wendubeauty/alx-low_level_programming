#include <stdio.h>
/**
 * main - Entry point
 * Return: always 0 (success)
 */
int main(void)
{
	int n;
	int m;

	for (n = 0; n < 9; n++)
	{
		for (m = n + 1; m <= 9; m++)
		{
			putchar('0' + n);
			putchar('0' + m);
			if (n != 8 || m != 9)
				putchar(',');
				putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
