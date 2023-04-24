#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_c(va_list l);
int print_s(va_list l);
int print_i(va_list l);
int print_bin(va_list l);
int print_oct(va_list l);
int print_x(va_list l);
int print_X(va_list l);
#endif /* MAIN_H */
