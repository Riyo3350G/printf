#include "main.h"

/**
 * hexa - Prints a char in hexadecimal upper format.
 * @n: The argument char.
 *
 * Return: Number of hexadecimal digits printed.
 */
int hexa(char n)
{
	char c;
	int ctr = 0, i = 0, j, up_hex[2];

	while (n > 0)
	{
		up_hex[i] = n % 16;
		n = n / 16;
		ctr++;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (up_hex[j] > 9)
			c = 'A' + (up_hex[j] % 10);
		else
			c = up_hex[j] + '0';
		write(1, &c, 1);
	}

	return (ctr);
}

/**
 * print_S - Prints a string, replacing non-printable characters with
 * hexadecimal representations
 * @l: A va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int print_S(va_list l)
{
	char *str = va_arg(l, char *);
	int ctr = 0, i = 0;

	if (str == NULL)
	{
		write(1, "\\x00", 4);
		return (4);
	}

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write(1, "\\x", 2);
			ctr += 2;
			if (str[i] < 16)
			{
				write(1, '0', 1);
				ctr++;
			}
			ctr += hexa(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			ctr++;
		}

		i++;
	}

	return (ctr);
}
