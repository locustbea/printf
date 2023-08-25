#include "main.h"

void print_my_buff(char my_buff[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, breadth, my_pre, size, buff_index = 0;
	va_list list;
	char my_buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_buff[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_my_buff(my_buff, &buff_index);
			printed_chars++;
		}
		else
		{
			print_my_buff(my_buff, &buff_index);
			flags = my_getf(format, &i);
			breadth = my_getw(format, &i, list);
			my_pre = my_getp(format, &i, list);
			size = my_gets(format, &i);
			++i;
			printed = my_ph(format, &i, list, my_buff,
				flags, breadth, my_pre, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_my_buff(my_buff, &buff_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_my_buff - Prints the contents of the my_buff if it exist
 * @my_buff: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_my_buff(char my_buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &my_buff[0], *buff_index);

	*buff_index = 0;
}

