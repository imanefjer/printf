#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_I - prints an integer
 * @arg: Argument
 * Return: nothing
 */
int  print_I(va_list arg)
{
	int i;
	char str[12];
	char output[12];
	int j = 0;
	int k = 0;
	int negative = 0;
	i = va_arg(arg, int);
	if (i < 0)
	{
		negative = 1;
		i = -i;
	}
	do {
		str[j++] = i % 10 + '0';
		i /= 10;
	} while (i > 0);
	if (negative == 1)
	{
		str[j++] = '-';
	}
	for (k = 0; k < j; k++)
	{
	output[k] = str[j - k - 1];
	}
	output[j] = '\0';
	write(1, output, j);
	return (1);
}
