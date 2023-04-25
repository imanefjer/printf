#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int length(char str[]);
int print_S(va_list arg);
int print_C(va_list arg);
void print_I(va_list arg);
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
		 {"i", print_I}
	};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
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
			while (i < 3)
			{
				if (format[j + 1] == *formats[i].format)
				{
					len += formats[i].f(arg);
					check = 1;
				}
				i++;
			}

			if (check == 0)
			{
				write(1, (format + j), 1);
				len++;
				if (format[j + 1] != '%')
				{
					write(1, (format + j + 1), 1);
					len++;
				}
			}
			j++;
		}
		else
		{
			len++;
			write(1, (format + j), 1);
		}
		j++;
	}
	va_end(arg);
	return (len);
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
	if (x == NULL)
	{
		x = "(NULL)";
	}
	len = length(x);
	write(1, x, len);
	return (len);
}

/**
 * print_C - writes the character c to stdout
 * @arg: Argument
 * Return: nothing
 */
int  print_C(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	if (c > 0)
		write(1, &c, 1);
	return (1);
}
/**
 * print_I - prints an integer
 * @arg: Argument
 * Return: nothing
 */
void print_I(va_list arg)
{
        int i ;
        char str[12];
        char output[12];
        int j = 0 ;
        int k = 0;
        int negative = 0;
        i = va_arg(arg, int);

        if (i < 0)
        {
                negative = 1;
                i = -i ;
        }
        do {
                str[j++] = i% 10 +'0';
                i /= 10;
        } while (i > 0);

        if (negative == 1) {
                str[j++] ='-';
        }
        for(k = 0; k < j; k++){
                output[k] = str[j-k-1];
        }
        output[j] = '\0';

        write(1,output, j);
}
