#include "main.h"

/**
 * print_i - Prints an integer
 * @l: List of arguments
 *
 * Return: Number of digits printed
 */
int print_i(va_list l)
{
    int ctr = 0, n;
    int input = va_arg(l, int);
    unsigned int countn = 1;
    unsigned int number;
    char c;

    if (input < 0)
    {
        i = '-';
        ctr += write(STDOUT_FILENO, &c, 1);
        number = (unsigned long) (-1 * input);
    }
    else
    {
        number = (unsigned long) input;
    }

    input = number;

    while (number >= 10)
    {
        number /= 10;
        countn *= 10;
    }

    while (countn >= 1)
    {
        n = (int) ((input / countn) % 10);
        c = n + '0';
        write(STDOUT_FILENO, &c, 1);
        countn /= 10;
        ctr++;
    }

    return (ctr);
}

/**
 * print_i - Prints an unsigned integer
 * @l: List of arguments
 *
 * Return: Number of digits printed
 */
int print_u(va_list l)
{
	int ctr = 0;
	unsigned int input = va_arg(l, unsigned int);


}
