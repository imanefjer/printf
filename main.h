#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct formats
{
	char *format;
	int (*f)(va_list arg);
} format_W;

int _printf(const char *format, ...);
int print_I(va_list arg);
#endif

