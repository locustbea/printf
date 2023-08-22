#include "main.h"

/**
 * binary_p - this func prints numbers in base 2
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int binary_p(va_list l, my_flags_t *b)
{
	unsigned int n = va_arg(l, unsigned int);
	char *str = my_conv(n, 2, 0);

	(void)b;
	return (_puts(str));
}

/**
 * octal_p - this func prints numbers in base 8
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int octal_p(va_list l, my_flags_t *b)
{
	unsigned int n = va_arg(l, unsigned int);
	char *str = my_conv(n, 8, 0);
	int counter = 0;

	if (b->my_hash == 1 && str[0] != '0')
	counter += _putchar('0');
	counter += _puts(str);
	return (counter);
}

/**
 * hexa_p - This func prints numbers in base 16
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int hexa_p(va_list l, my_flags_t *b)
{
	unsigned int n = va_arg(l, unsigned int);
	char *str = my_conv(n, 16, 1);
	int counter = 0;

	if (b->my_hash == 1 && str[0] != '0')
	counter += _puts("0x");
	counter += (_puts(str));
	return (counter);
}

/**
 * hexabig_p - This funct prints numbers in base 16
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int hexabig_p(va_list l, my_flags_t *b)
{
	unsigned int n = va_arg(l, unsigned int);
	char *str = my_conv(n, 16, 0);
	int counter = 0;

	if (b->my_hash == 1 && str[0] != '0');
	counter += _puts('0X');
	counter += _puts(str);
	return (counter);
}
