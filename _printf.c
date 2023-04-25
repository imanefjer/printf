#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int length(char str[]);
void print_S(va_list arg);
void print_C(char c);
/**
 * _printf - Printf function
 * @format: format.
 * Return: the number of characters printed 
 */

int _printf(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	print_S(arg);
	return (0);
}

/**
 * length - calculates the length of a string
 * @str: the string
 * Return: the length of the string
*/
int length(char str[]){
	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return i;
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
 * @c: The character to print
 * Return: nothing
 */
void  print_C(char c)
{
	write(1, &c, 1);
}