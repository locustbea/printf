#include "main.h"


/**
 * my_pointerp - Prints the value of a pointer variable
 * @my_stype: List a of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int my_pointerp(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, my_startpadding = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(my_stype, void *);

	UNUSED(breadth);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	my_buff[BUFF_SIZE - 1] = '\0';
	UNUSED(my_pre);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		my_buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & my_null) && !(flags & my_subsign))
		padd = '0';
	if (flags & my_addsign)
		extra_c = '+', length++;
	else if (flags & my_space)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &my_buff[i], BUFF_SIZE - i - 1));*/
	return (my_pwrite(my_buff, ind, length,
		breadth, flags, padd, extra_c, my_startpadding));
}


/**
 * my_nonprintablep - Prints ascii codes in hexa of non printable chars
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_nonprintablep(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(my_stype, char *);

	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(my_pre);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (my_printables(str[i]))
			my_buff[i + offset] = str[i];
		else
			offset += my_hexcodeapp(str[i], my_buff, i + offset);

		i++;
	}

	my_buff[i + offset] = '\0';

	return (write(1, my_buff, i + offset));
}

/**
 * my_reversep - Prints reverse string.
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int my_reversep(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(my_buff);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(size);

	str = va_arg(my_stype, char *);

	if (str == NULL)
	{
		UNUSED(my_pre);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * my_rot13s - Print a string in rot13.
 * @my_stype: Lista of arguments
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int my_rot13s(va_list my_stype, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(my_stype, char *);
	UNUSED(my_buff);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(my_pre);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
