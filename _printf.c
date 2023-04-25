#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int length(char str[]);
int print_S(va_list arg);
void print_C(va_list arg);

/**
 * _printf - Printf function
 * @format: format.
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list arg;
	int check = 0;
	format_W formats[] = {
		{"s", print_S},
		{"c", print_C},
		{"S", print_S},
		{"C", print_C}
	};

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg, format);

	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			i = 0;
			check = 0;
			while (i < 2)
			{
				if (format[j + 1] == *formats[i].format)
				{
					len + = formats[i].f(arg);
					check = 1;
					j += 2;
				}
				i++;
			}

			if (check == 0)
			{
				write(1, (format + j), 1);
				if (format[j + 1] != '%')
				{
					write(1, (format + j + 1), 1);
				}
			}
			/*j++;*/
		}
		else
		{
			write(1, (format + j), 1);
		}
		len++;
		j++;
	}
	va_end(arg);
	return (j);
}

/**
 * length - calculates the length of a string
 * @str: the string
 * Return: the length of the string
*/
int length(char str[])
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
/**
 * print_S - prints a string
 * @arg: Argument
 * Return: nothing
*/
int print_S(va_list arg)
{
	char *x;
	int len = 0;

	x = va_arg(arg, char *);
	len = lenght(x);
	if (x == NULL)
	{
		len = length("(NULL)");
		return (len) ;
	}
	write(1, x, length(x));
	return (len);
}

/**
 * print_C - writes the character c to stdout
 * @arg: Argument
 * Return: nothing
 */
void  print_C(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	if (c > 0)
		write(1, &c, 1);
}
