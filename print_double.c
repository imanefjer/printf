#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_doube - prints a double value
 * @arg: argument
 *
 * Return: word count
 */
int length(int arg)
{
	int i = 0;
	int tmp = arg;

	while (arg / 10 != 0)
	{
		arg = arg / 10;
	}
	arg ++;
	return (i);
}
int print_d(va_list arg)
{
	int x;
	x = va_arg(arg, int);
	write(1, x, length(x));
}
