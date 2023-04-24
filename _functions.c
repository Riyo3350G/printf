#include "main.h"

/**
 * print_c - Prints a character
 * @l: List of arguments
 *
 * Return: 1
 */
int print_c(va_list l)
{
	int retVal;
	char c = va_arg(l, int);

	retVal = write(STDOUT_FILENO, &c, 1);
	return (retVal);
}

/**
 * print_s - Prints a string
 * @l: List of arguments
 *
 * Return: Number of characters printed
 */
int print_s(va_list l)
{
	char *str = NULL;
	int ctr = 0, retVal;

	str = va_arg(l, char*);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str != '\0')
	{
		retVal = write(STDOUT_FILENO, str, 1);
		if (retVal == -1)
			return (-1);
		str++;
		ctr++;
	}
	return (ctr);
}

/**
 * print_rev - Prints a string in reverse
 * @l: Argument list containing the string to be printed
 *
 * Return: The length of the string
 */
int print_rev(va_list l)
{
	int count_fun = 0, i = 0;
	char *s = va_arg(l, char *);

	if (!s)
		s = "(null)";
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		count_fun += write(1, &s[i], 1);
		i--;
	}
	count_fun--;
	return (count_fun);
}
