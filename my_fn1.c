#include "main.h"


/**
 * my_characterp - Prints a char
 * @my_stype: List a of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int my_characterp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size)
{
	char c = va_arg(my_stype, int);

	return (my_charwrite(c, my_buff, flags, breadth, my_pre, size));
}

/**
 * my_stringp - Prints a string
 * @my_stype: List a of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int my_stringp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size)
{
	int length = 0, i;
	char *str = va_arg(my_stype, char *);

	UNUSED(my_buff);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(my_pre);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (my_pre >= 6)
	str = "      ";
	}
	while (str[length] != '\0')
	length++;
	if (my_pre >= 0 && my_pre < length)
	length = my_pre;
	if (breadth > length)
	{
	if (flags & my_subsign)
	{
	write(1, &str[0], length);
	for (i = breadth - length; i > 0; i--)
	write(1, " ", 1);
	return (breadth);
	}
	else
	{
	for (i = breadth - length; i > 0; i--)
	write(1, " ", 1);
	write(1, &str[0], length);
	return (breadth);
	}
	}
	return (write(1, str, length));
}

/**
 * my_percentp - Prints a percent sign
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int my_percentp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size)
{
	UNUSED(my_stype);
	UNUSED(my_buff);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(my_pre);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * my_intp - Print int
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int my_intp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(my_stype, long int);
	unsigned long int num;

	n = my_convlong(n, size);
	if (n == 0)
	my_buff[i--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
	num = (unsigned long int)((-1) * n);
	is_negative = 1;
	}
	while (num > 0)
	{
	my_buff[i--] = (num % 10) + '0';
	num /= 10;
	}
	i++;
	return (my_nwrite(is_negative, i, my_buff, flags, breadth, my_pre, size));
}

/**
 * my_binaryp - Prints an unsigned number
 * @my_stype: va_List of arguments
 * @my_buff: this is a buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int my_binaryp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(my_buff);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(my_pre);
	UNUSED(size);

	n = va_arg(my_stype, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
	m /= 2;
	a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
	sum += a[i];
	if (sum || i == 31)
	{
	char z = '0' + a[i];

	write(1, &z, 1);
	count++;
	}
	}
	return (count);
}
