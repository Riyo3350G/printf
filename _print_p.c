#include "main.h"

/**
 * hexal - Prints a char in hexadecimal lower format.
 * @n: The argument char.
 *
 * Return: Number of hexadecimal digits printed.
 */
int hexal(unsigned long int n)
{
	char c;
	int ctr = 0, i = 0, j;
	unsigned long int m = n;
	int *up_hex = NULL;

	do {
		m /= 16;
		ctr++;
	} while (m > 0);

	up_hex = malloc(sizeof(int) * ctr);
	if (up_hex == NULL)
		return (-1);

	while (n > 0)
	{
		up_hex[i] = n % 16;
		n = n / 16;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (up_hex[j] > 9)
			c = 'a' + (up_hex[j] % 10);
		else
			c = up_hex[j] + '0';
		write(1, &c, 1);
	}

	free(up_hex);

	return (ctr);
}

/**
 * print_p - prints an hexgecimal number.
 * @l: The arguments.
 *
 * Return: The counter.
 */
int print_p(va_list l)
{
	int ctr = 0;
	void *p;

	p = va_arg(l, void*);

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	write(1, "0x", 2);
	ctr += 2;

	ctr += hexal((unsigned long int)p);

	return (ctr);
}
