#include "main.h"

/**
 * string_p - this function prints every character in a string
 * @l: va_list of arguments
 * @b: this is the pointer to the struct my_flags
 * Return: characters
 */

int string_p(va_list l, my_flags_t *b)
{
	char *a = va_arg(l, char *);

	(void)b;
	if (!a)
	a = "(null)";
	return (_puts(a));
}

/**
 * stringbig_p - this func prints Non Printable characters
 * @l: va_list of arguments
 * @b: this is the pointer to the struct my_flags
 * Return: characters
 */

int stringbig_p(va_list l, my_flags_t *b)
{
	int a;
	int counter = 0;
	char *r;
	char *s = va_arg(l, char *);

	(void)b;
	if (!s)
	return (_puts("null"));

	for (a = 0; s[a]; a++)
	{
	if (s[a] > 0 && (s[a] < 32 || s[a] >= 127))
	{
	_puts("\\x");
	counter += 2;
	r = my_conv(s[a], 16, 0);
	if (!r[1])
	counter += _putchar('0');
	counter += _puts(r);
	}
	else
	counter += _putchar(s[a]);
	}
	return (counter);
}

/**
 * character_p - prints a char
 * @l: va_lists of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int character_p(va_list l, my_flags_t *b)
{
	(void)b;
	_putchar(va_arg(l, int));
	return (1);
}
