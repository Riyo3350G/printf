#include "main.h"

/**
 * print_bin - Prints an unsigned int in binary format.
 * @l: List of arguments.
 *
 * Return: Number of binary digits printed.
 */
int print_oct(va_list l)
{
	unsigned int n = va_arg(l, unsigned int);
	char c;
	int ctr = 0, i = 0, j = 0, octal[32];

	if (n == 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		while (n > 0)
		{
			octal[i] = n % 8;																	
			n = n / 8;
			ctr++;
			i++;
		}

		for (j = i - 1; j >= 0; j--)
		{
			c = octal[j] + '0';
			write(1, &c, 1);																	
		}
		return (ctr);
	}
}
