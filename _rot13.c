#include "main.h"
/**
 * print_rot13 - Encodes a string using rot13
 * @l: Argument list
 *
 * Return: Number of characters printed
 */
int print_rot13(va_list l)
{
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	int i, ctr = 0;
	char *str = va_arg(l, char*);

	if (str == NULL)
	{
		str = "(null)";
		return (-1);
	}
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			for (i = 0; i < 26; i++)
			{
				if (upper[i] == *str)
					break;
			}
			i += 13;
			if (i > 26)
				i = i % 26;
			write(1, &upper[i], 1);
		}
		else if (*str >= 'a' && *str <= 'z')
		{
			for (i = 0; i < 26; i++)
				if (lower[i] == *str)
					break;
			i += 13;
			if (i > 26)
				i = i % 26;
			write(1, &lower[i], 1);
		}
		else
			write(1, str, 1);
		ctr++;
		str++;
	}
	return (ctr);
}
