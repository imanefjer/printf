#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
void print_number(int n);
int count_digit(int i);
/**
 * print_I - prints an integer
 * @arg: Argument
 * Return: nothing
 */
int print_I(va_list arg)
{
	int n = va_arg(arg, int);
	int res =count_digit(n);
	print_number(n);
	return (res);
}
void print_number(int n)
{
	int n1;
	char dash[2] ="-";
	char num[2];
	if (n < 0)
	{
		write(1,dash,1);
		n1 =-n;
	}
	else 
		n1 = n;
	if (n1 /10)
		print_number(n1/10);
	num[0] = (n1 % 10) + '0'; 
	write(1, num ,1);
}
int count_digit(int i)
{
	unsigned int count = 0;
	unsigned int u;

	if (i < 0)
		u = i* -1;
	else 
		u = i;
	while (u != 0)
	{
		u/=10;
		count++;
	}
	return (count);
}

