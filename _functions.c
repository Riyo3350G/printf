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

/**
 * print_rev - Prints a string in reverse
 * @l: Argument list containing the string to be printed
 *
 * Return: The length of the string
 */
int print_rev(va_list l)
{
        char *str = va_arg(l, char *);
        int length = 0, j;

        while (*str != '\0')
        {
                length++;
                str++;
        }

        for (j = length - 1; j >= 0; j--)
        {
                write(1, &str[j], 1);
        }

        return (length);
}

