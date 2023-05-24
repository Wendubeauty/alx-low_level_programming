#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, otherwise 1
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;

    if (argc != 4)
    {
        printf("Error\n");
        return (1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    if (num2 == 0 && (argv[2][0] == '/' || argv[2][0] == '%'))
    {
        printf("Error\n");
        return (1);
    }

    result = (*get_op_func(argv[2]))(num1, num2);
    printf("%d\n", result);

    return (0);
}

