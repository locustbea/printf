#include "main.h"

/**
 * address_p - this func prints address of input in a hexa
 * @l: va_list args from _printf
 * @b: this is a pointer to the struct flags
 * Return: the char printed
 */

int address_p(va_list l, my_flags_t *b)
{
	unsigned long int a = va_arg(l, unsigned long int);
	char *str;

	register int counter = 0;

	(void)b;
	if (!a)
	return (_puts("(nil)"));
	str = my_conv(a, 16, 1);
	counter += _puts("0x");
	counter += _puts(str);
	return (counter);
}

