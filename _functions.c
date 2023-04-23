#include "main.h"

/**
 * print_c - Prints a character
 * @l: List of arguments
 *
 * Return: 1
 */
int print_c(va_list l)
{
	char c = va_arg(l, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_s - Prints a string
 * @l: List of arguments
 *
 * Return: Number of characters printed
 */
int print_s(va_list l)
{
	char *str = va_arg(l, char*);
	char *i;
	int ctr = 0;
	
	for (i = str; *i != '\0'; i++)
	{
		ctr++;
		write(1, i, 1);
	}
	return (ctr);
}

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
	int countn = 1;
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

	return ctr;
}
