#include "main.h"


/**
 * my_printables - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int my_printables(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * my_hexcodeapp - Append ascci in hexadecimal code to my_buff
 * @my_buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int my_hexcodeapp(char ascii_code, char my_buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	my_buff[i++] = '\\';
	my_buff[i++] = 'x';

	my_buff[i++] = map_to[ascii_code / 16];
	my_buff[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * my_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int my_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * my_convlong - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int my_convlong(long int num, int size)
{
	if (size == my_longs)
		return (num);
	else if (size == my_shorts)
		return ((short)num);

	return ((int)num);
}

/**
 * my_convunsgned - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int my_convunsgned(unsigned long int num, int size)
{
	if (size == my_longs)
		return (num);
	else if (size == my_shorts)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

