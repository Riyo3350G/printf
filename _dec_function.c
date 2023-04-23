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
	int a = va_arg(l, int);
	unsigned int countn = 1;
	unsigned int number;
	char c;

	if (a < 0)
	{
		c = '-';
		ctr += write(1, &c, 1);
		number = a * -1;
	}
	else
	{
		number = a;
	}
	a = number;

	while (number > 9)
	{
		number = number / 10;
		countn = countn * 10;
		ctr++;
	}

	while (countn >= 1)
	{
		n = (a / countn) % 10;
		c = n + '0';
		write(1, &c, 1);
		countn = countn / 10;
	}

	return (ctr);
}
