#include "main.h"

/**
 * my_unsignedp - Prints an unsigned number
 * @my_stype: List a of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int my_unsignedp(va_list my_stype, char my_buff[],
int flags, int breadth, int my_pre, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(my_stype, unsigned long int);

	num = my_convunsgned(num, size);

	if (num == 0)
	my_buff[i--] = '0';

	my_buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		my_buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (my_uwrite(0, i, my_buff, flags, breadth, my_pre, size));
}


/**
 * my_octalp - Prints an unsigned number in octal notation
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_octalp(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(my_stype, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(breadth);

	num = my_convunsgned(num, size);

	if (num == 0)
		my_buff[i--] = '0';

	my_buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		my_buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & my_hash && init_num != 0)
		my_buff[i--] = '0';

	i++;

	return (my_uwrite(0, i, my_buff, flags, breadth, my_pre, size));
}


/**
 * my_hexaD - Prints an unsigned number in hexadecimal notation
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_hexaD(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	return (my_hexap(my_stype, "0123456789abcdef", my_buff,
		flags, 'x', breadth, my_pre, size));
}


/**
 * my_hexabig - Prints an unsigned number in upper hexadecimal notation
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_hexabig(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	return (my_hexap(my_stype, "0123456789ABCDEF", my_buff,
		flags, 'X', breadth, my_pre, size));
}


/**
 * my_hexap - Prints a hexadecimal number in lower or upper
 * @my_stype: Lista of arguments
 * @map_to: Array of values to map the number to
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int my_hexap(va_list my_stype, char map_to[], char my_buff[],
	int flags, char flag_ch, int breadth, int my_pre, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(my_stype, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(breadth);

	num = my_convunsgned(num, size);

	if (num == 0)
		my_buff[i--] = '0';

	my_buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		my_buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & my_hash && init_num != 0)
	{
		my_buff[i--] = flag_ch;
		my_buff[i--] = '0';
	}

	i++;

	return (my_uwrite(0, i, my_buff, flags, breadth, my_pre, size));
}

