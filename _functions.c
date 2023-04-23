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
	write(STDOUT_FILENO, &c, 1);
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
	int ctr = 0;
	
	if (str == NULL)
	{
		str = "(null)";
	}
	
	while (*str != '\0')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
		ctr++;
	}
	return (ctr);
}

