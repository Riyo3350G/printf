#include "main.h"

/**
 * get_func - selects the appropriate function to perform
 * conversion based on the format specifier
 *
 * @l: arguments list
 * @k: character before format specifier
 * @c: format specifier character
 *
 * Return: number of characters printed
 */
int get_func(va_list l, char k, char c)
{
	int counter = 0;

	if (c == 'c')
		counter += print_c(l);
	else if (c == 's')
		counter += print_s(l);
	else if (c == 'd' || c == 'i')
		counter += print_i(l);
	else if (c == '%')
	{
		write(1, '%', 1);
		counter++;
	} else if (c == 'b')
	{
		counter += print_bin(l);
	} else if (c == 'o')
	{
		counter += print_oct(l);
	} else if (c == 'x')
	{
		counter += print_x(l);
	} else if (c == 'X')
	{
		counter += print_X(l);
	} else if (c == 'u')
	{
		counter += print_u(l);
	} else if (c == 'r')
	{
		counter += print_rev(l);
	} else if (c == 'R')
	{
		counter += print_rot13(l);
	} else
	{
		write(1, &k, 1);
		write(1, &c, 1);
		counter += 2;
	}
	return (counter);
}
