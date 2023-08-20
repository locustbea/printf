#include "main.h"

/**
 * _printf - A function that performs similar task to std printf
 * @format: a string that contains the specifiers and the chars
 * Description: This _printf func calls the my_getp func which will
 * ascertain which printing func to call based on the conversion specifiers
 * in the format string.
 * Return: outputs the string length
 */

int _printf(const char *format, ...)
{
	const char *pf;
	int (*my_printfunction)(va_list, my_flags_t *);
	va_list my_args;
	register int counter = 0;
	my_flags_t my_flags = {0, 0, 0};

	va_start(my_args, format);
	
	if ((format[0] == '%' && !format[1]) || !format)
	return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);
	for (pf = format; *pf; pf++)
	{
	if (*pf == '%')
	{
	pf++;
	if (*pf == '%')
	{
	counter += _putchar('%');
	continue;
	}
	while (my_getf(*pf, &my_flags))
	pf++;
	my_printfunction = my_getp(*pf);
	counter += (my_printfunction)
	? my_printfunction(my_args, &my_flags)
	: _printf("%%%c", *pf);
	}
	else
	counter += _putchar(*pf);
	}
	_putchar(-1);
	va_end(my_args);
	return (counter);
}
