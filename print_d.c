#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_d - prints a double value
 * @arg: argument
 *
 * Return: word count
 */
int len(char str[])
{

	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
int print_d(va_list arg)
{
	int x;

	x = va_arg(arg, int);
	write(1, &x, len((char *)x));
	return (len(x));
}
