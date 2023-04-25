#include "main.h"

/**
 * print_rot13 - Encodes a string using rot13
 * @l: Argument list
 *
 * Return: Number of characters printed
 */
int print_rot13(va_list l)
{
	int i, j, count = 0;
	char *str, alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	str = va_arg(l, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; alph[j]; j++)
		{
			if (str[i] == alph[j])
			{
				count += write(1, rot13[j], 1);
				break;
			}
		}
		if (!alph[j])
		{
			count += write(1, str[i], 1);
		}
	}
	return (count);
}
