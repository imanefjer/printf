#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int length(char str[]);
void print_S(va_list arg);
void print_C(va_list arg);

/**
 * _printf - Printf function
 * @format: format.
 * Return: the number of characters printed 
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0;
	va_list arg;
	format_W formats[] = {
		{"s", print_S},
		{"c", print_C}
	};
	va_start(arg, format);
	while (*format && *(format + j)){
		if (*(format + j) == '%'){
			i = 0;
			while (i < 2){
				if (*(format + j + 1) == *formats[i].format){
					formats[i].f(arg);
					k++;
				}
				else
					{
						write(1, (format + j), 1);
					}
				i++;
			}
			j++;
		}
		else{
			write(1, (format + j), 1);
		}
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
int length(char str[]){
	int i = 0;
	while(str[i]){
		i++;
	}
	return (i);
}
/**
 * print_S - prints a string
 * @arg: Argument
 * Return: nothing
*/
void print_S(va_list arg)
{
	char *x;

	x = va_arg(arg, char *);
	write(1, x, length(x));
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
	write(1, &c, 1);
}
