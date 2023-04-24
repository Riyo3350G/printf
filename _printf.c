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

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i] || (format[i] == ' ' && !format[i + 1]))
			{
				counter = -1;
				break;
			}
			else if (format[i])
			{
				counter += get_func(l, format[i - 1], format[i]);
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
	return (counter);
}
