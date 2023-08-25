#include "main.h"


/**
 * my_charwrite - Prints a string
 * @c: char my_stype.
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags.
 * @breadth: get breadth.
 * @my_pre: my_pre specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int my_charwrite(char c, char my_buff[],
int flags, int breadth, int my_pre, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(my_pre);
	UNUSED(size);

	if (flags & my_null)
		padd = '0';

	my_buff[i++] = c;
	my_buff[i] = '\0';

	if (breadth > 1)
	{
		my_buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < breadth - 1; i++)
			my_buff[BUFF_SIZE - i - 2] = padd;

		if (flags & my_subsign)
			return (write(1, &my_buff[0], 1) +
					write(1, &my_buff[BUFF_SIZE - i - 1], breadth - 1));
		else
			return (write(1, &my_buff[BUFF_SIZE - i - 1], breadth - 1) +
					write(1, &my_buff[0], 1));
	}

	return (write(1, &my_buff[0], 1));
}

/**
 * my_nwrite - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char my_stype.
 * @my_buff: my_buff array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int my_nwrite(int is_negative, int ind, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & my_null) && !(flags & my_subsign))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & my_addsign)
		extra_ch = '+';
	else if (flags & my_space)
		extra_ch = ' ';

	return (my_nmwrite(ind, my_buff, flags, breadth, my_pre,
		length, padd, extra_ch));
}

/**
 * my_nmwrite - Write a number using a bufffer
 * @ind: Index at which the number starts on the my_buff
 * @my_buff: my_buff
 * @flags: Flags
 * @breadth: breadth
 * @prec: my_pre specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int my_nmwrite(int ind, char my_buff[],
	int flags, int breadth, int prec,
	int length, char padd, char extra_c)
{
	int i, my_startpadding = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && my_buff[ind] == '0' && breadth == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && my_buff[ind] == '0')
		my_buff[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		my_buff[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (breadth > length)
	{
		for (i = 1; i < breadth - length + 1; i++)
			my_buff[i] = padd;
		my_buff[i] = '\0';
		if (flags & my_subsign && padd == ' ')
		{
			if (extra_c)
				my_buff[--ind] = extra_c;
			return (write(1, &my_buff[ind], length) + write(1, &my_buff[1], i - 1));
		}
		else if (!(flags & my_subsign) && padd == ' ')
		{
			if (extra_c)
				my_buff[--ind] = extra_c;
			return (write(1, &my_buff[1], i - 1) + write(1, &my_buff[ind], length));
		}
		else if (!(flags & my_subsign) && padd == '0')
		{
			if (extra_c)
				my_buff[--my_startpadding] = extra_c;
			return (write(1, &my_buff[my_startpadding], i - my_startpadding) +
				write(1, &my_buff[ind], length - (1 - my_startpadding)));
		}
	}
	if (extra_c)
		my_buff[--ind] = extra_c;
	return (write(1, &my_buff[ind], length));
}

/**
 * my_uwrite - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the my_buff
 * @my_buff: Array of chars
 * @flags: Flags specifiers
 * @breadth: breadth specifier
 * @my_pre: my_pre specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int my_uwrite(int is_negative, int ind,
	char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (my_pre == 0 && ind == BUFF_SIZE - 2 && my_buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (my_pre > 0 && my_pre < length)
		padd = ' ';

	while (my_pre > length)
	{
		my_buff[--ind] = '0';
		length++;
	}

	if ((flags & my_null) && !(flags & my_subsign))
		padd = '0';

	if (breadth > length)
	{
		for (i = 0; i < breadth - length; i++)
			my_buff[i] = padd;

		my_buff[i] = '\0';

		if (flags & my_subsign)
		{
			return (write(1, &my_buff[ind], length) + write(1, &my_buff[0], i));
		}
		else /* Asign extra char to left of padding [padd>my_buff]*/
		{
			return (write(1, &my_buff[0], i) + write(1, &my_buff[ind], length));
		}
	}

	return (write(1, &my_buff[ind], length));
}

/**
 * my_pwrite - Write a memory address
 * @my_buff: Arrays of chars
 * @ind: Index at which the number starts in the my_buff
 * @length: Length of number
 * @breadth: breadth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @my_startpadding: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int my_pwrite(char my_buff[], int ind, int length,
	int breadth, int flags, char padd, char extra_c, int my_startpadding)
{
	int i;

	if (breadth > length)
	{
		for (i = 3; i < breadth - length + 3; i++)
			my_buff[i] = padd;
		my_buff[i] = '\0';
		if (flags & my_subsign && padd == ' ')
		{
			my_buff[--ind] = 'x';
			my_buff[--ind] = '0';
			if (extra_c)
				my_buff[--ind] = extra_c;
			return (write(1, &my_buff[ind], length) + write(1, &my_buff[3], i - 3));
		}
		else if (!(flags & my_subsign) && padd == ' ')
		{
			my_buff[--ind] = 'x';
			my_buff[--ind] = '0';
			if (extra_c)
				my_buff[--ind] = extra_c;
			return (write(1, &my_buff[3], i - 3) + write(1, &my_buff[ind], length));
		}
		else if (!(flags & my_subsign) && padd == '0')
		{
			if (extra_c)
				my_buff[--my_startpadding] = extra_c;
			my_buff[1] = '0';
			my_buff[2] = 'x';
			return (write(1, &my_buff[my_startpadding], i - my_startpadding) +
				write(1, &my_buff[ind], length - (1 - my_startpadding) - 2));
		}
	}
	my_buff[--ind] = 'x';
	my_buff[--ind] = '0';
	if (extra_c)
		my_buff[--ind] = extra_c;
	return (write(1, &my_buff[ind], BUFF_SIZE - ind - 1));
}


