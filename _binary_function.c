#include "main.h"

/**
 * print_b - prints an unsigned integers in binary
 * @l: the list of arguments
 *
 * Return: the number of characters printed
 */
int print_b(va_list l)
{
    unsigned int n = va_arg(l, unsigned int);
    unsigned int binary = 0, base = 1;

    while (n > 0)
    {
        binary += (n % 2) * base;
        n /= 2;
        base *= 10;
    }

    int len = 0;
    char buffer[32]; // max length of unsigned int in binary is 32 bits

    while (base > 1)
    {
        base /= 10;
        buffer[len] = binary / base + '0';
        binary %= base;
        len++;
    }

    write(STDOUT_FILENO, buffer, len);
    return (len);
}
