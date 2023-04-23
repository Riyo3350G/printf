#include "main.h"

/**
 * _printf - Function that produces output according to a format.
 * @format: Format specifies
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list l;
	int i = 0;
	int counter = 0;

	va_start(l, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				if (format[i] == 'c')
				{
					counter += print_c(l);
				}
				else if (format[i] == 's')
				{
					counter += print_s(l);
				}
				else if (format[i] == 'd' || format[i] == 'i')
				{
					counter += print_i(l);
				}
				else if (format[i] == '%')
				{
					write(1, "%", 1);
					counter++;
				}else if (format[i] == 'b')
				{
					counter += print_bin(l);
				}else{
					write(1, &format[i-1], 1);
					write(1, &format[i],1);
					counter = counter + 2;
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}

	va_end(l);
	return counter;
}
