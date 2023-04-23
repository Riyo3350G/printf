#include "main.h"

/**
 * print_bin - Prints an unsigned int in binary format
 * @l: List of arguments
 *
 * Return: Number of binary digits printed
 */
int print_bin(va_list l)
{
	unsigned int input = va_arg(l, unsigned int);
	char binary_digit;
	int num_digits = 0, index = 0;
	int *binary_array = malloc(32 * sizeof(int));

	if (binary_array == NULL)
		return (-1); // handle allocation failure

	if (input == 0)
	{
		binary_digit = input + '0';
		write(1, &binary_digit, 1);
		num_digits++;
	}
	else
	{
		while (input > 0)
		{
			binary_array[index] = input & 1;
			input >>= 1;
			num_digits++;
			index++;
		}

		for (int j = index - 1; j >= 0; j--)
		{
			binary_digit = binary_array[j] + '0';
			write(1, &binary_digit, 1);
		}
	}

	free(binary_array);
	return num_digits;
}
