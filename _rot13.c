#include "main.h"

/**
 * print_rot13 - Encodes a string using rot13
 * @l: Argument list
 *
 * Return: Number of characters printed
 */
int print_rot13(va_list l)
{
	char *upper = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char *lower = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
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
			if ((i + 13) > 26)
				i = (i + 13) % 26;
			write(1, &upper[i], 1);
		} else if (*str >= 'a' && *str <= 'z')
		{
			for (i = 0; i < 26; i++)
				if (lower[i] == *str)
					break;
			if ((i + 13) > 26)
				i = (i + 13) % 26;
			write(1, &lower[i], 1);
		} else
			write(1, str, 1);
		ctr++;
		str++;
	}
	return (ctr);
}
