#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _print_rev_recursion - prints a string in reverse.
 * @s: string to print
 *
 * Return: nothing
 */
void _print_rev_recursion(char *s)
{
	char c = *s;

	if (*s)
	{
		_print_rev_recursion(++s);
	write(1, &c, 1);
	}
}
/**
 * print_rst - print result
 * @n: number to print
 * @l: longth
 *
 * Return: nothing
 */
void print_rst(long int n, long int l)
{
	char *num;
	long int n1 = n;
	int i = 0;

	num = malloc(sizeof(char) * l);

	while (n1 > 0)
	{
		num[i] = (n1 % 10) + '0';
		i++;
		n1 /= 10;
	}
	_print_rev_recursion(num);
	free(num);
}
/**
 * _pow - returns the value of x raised to the power of y.
 * @x: int
 * @y: power
 *
 * Return: x power y
 */
int _pow(int x, int y)
{
	if (y == 0)
		return (1);
	else
		return (x * _pow(x, y - 1));
}
/**
 * print_B -  the unsigned int argument is converted to binary
 * @arg: argument
 *
 * Return: nothing
 */
int print_B(va_list arg)
{
	unsigned long int num, rst;
	int rest, lon;
	long int  power = 0;

	num = va_arg(arg, unsigned int);
	while (num > 0)
	{
		rest = num % 2;
		rst += _pow(10, power) * rest;
		if (rest == 0 && lon == 0)
			rst = 0;
		power++;
		num =  num / 2;
		lon++;
	}
	print_rst(rst, lon);
	return (lon);
}
