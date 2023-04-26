#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/**
 * stuct formats - formats
 * @format: format that are possible
 * @f pointer to the printing function
 */
typedef struct formats
{
	char *format;
	int (*f)(va_list arg);
} format_W;

int _printf(const char *format, ...);
int print_d(va_list arg);
int print_I(va_list arg);
#endif

