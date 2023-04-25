#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int x = 0, x2 = 0;
	int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
   x =  _printf("Length:[%d, %i]\n", len, len);
      printf("%d\n" , x);
   x2 =  printf("Length:[%d, %i] : x = %d - x2 = %d\n", len2, len2, x, x2);
printf("%d\n" , x2);
   x =  _printf("Negative:[%d]\n", -762534);
    printf("%d\n" , x);
    x2 = printf("Negative:[%d]\n", -762534);
    printf("%d\n" , x2);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    x = _printf("String:[%s]\n", "I am a string !");

    x2 = printf("String:[%s]\n", "I am a string !");
    printf("%d\n" , x2);
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
   _printf("hola %s\n");
  printf("Hole %c\n") ;
    return (0);
}
