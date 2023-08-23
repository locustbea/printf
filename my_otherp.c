#include "main.h"

/**
 * rot13_p - uses rot13 to print a string
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the length of str printed
 */

int rot13_p(va_list l, my_flags_t *b)
{
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int m;
	int n;
	char *s = va_arg(l, char *);

	(void)b;
	for (n = 0; s[n]; n++)
	{
	if (s[n] < 'A' || (s[n] > 'Z' && s[n] < 'a') || s[n] > 'z')
	_putchar(s[n]);
	else
	{
	for (m = 0; m <= 52; m++)
	{
	if (s[n] == rot13[m])
	_putchar(ROT13[m]);
	}
	}
	}
	return (n);
}

/**
 * reverse_p - this func prints a string in reverse
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the len of str printed
 */

int reverse_p(va_list l, my_flags_t *b)
{
	int m = 0;
	int n;
	char *s = va_arg(l, char *);

	if (!s)
	s = "(null)";
	while (s[m])
	m++;
	for (n = m - 1; n >= 0; n--)
	_putchar(s[n]);
	return (m);
}

/**
 * percent_p - this func prints a prints a percent sign '%'
 * @l: va_list of arguments
 * @b: pointer to the struct my_flags
 * Return: the character printed
 */

int percent_p(va_list l, my_flags_t *b)
{
	(void)b;
	(void)l;
	return (_putchar('%'));
}
