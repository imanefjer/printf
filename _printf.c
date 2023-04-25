#include "main.h"

int length(char str[]);
/**
 * _printf - Printf function
 * @format: format.
 * Return: the number of characters printed 
 */

int _printf(const char *format, ...)
{
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
