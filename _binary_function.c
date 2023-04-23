#include "main.h"

/**
 * print_bin - Prints an unsigned int in binary format
 * @l: List of arguments
 *
 * Return: Number of binary digits printed
 */
int print_bin(va_list l)
{
	unsigned int n = va_arg(l, unsigned int), a;
	char c;
	int ctr = 0, i = 0, retval;
	char *binary;
	
	a = n;
	
	while (a > 0)
	{
		ctr++;
		a /= 2;
	}
	
	binary = malloc(sizeof(char) * (ctr + 1));

	if (n < 1)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		if (binary == NULL)
			return (-1);
		for (i = 1; i < ctr + 1; i++)
		{
			binary[ctr - i] = n % 2;
			n = n / 2;
		}
		for (i = 0; i < ctr; i++)
		{
			c = binary[i] + '0';
			retval = write(1, &c, 1);

			if (retval == -1)
			{
				free(binary);
				return (-1);
			}
		}
	}
	free(binary);
	return ctr;
}
