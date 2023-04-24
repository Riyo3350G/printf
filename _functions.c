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
	char *str = NULL;
	int ctr = 0;
	
	str = va_arg(l, char*);
	
	if (str == NULL)
	{
		return (0);
	}
	
	while (*str != '\0')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
		ctr++;
	}
	return (ctr);
}
