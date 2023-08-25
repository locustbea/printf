#include "main.h"
/**
 * my_ph - Prints an argument based on its type
 * @my_format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @my_buff: my_buff array to handle print.
 * @flags: Calculates active flags
 * @breadth: get breadth.
 * @my_pre: my_pre specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int my_ph(const char *my_format, int *ind, va_list list, char my_buff[],
	int flags, int breadth, int my_pre, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	my_format_t my_format_my_stype[] = {
		{'c', my_characterp}, {'s', my_stringp}, {'%', my_percentp},
		{'i', my_intp}, {'d', my_intp}, {'b', my_binaryp},
		{'u', my_unsignedp}, {'o', my_octalp}, {'x', my_hexaD},
		{'X', my_hexabig}, {'p', my_pointerp}, {'S', my_nonprintablep},
		{'r', my_reversep}, {'R', my_rot13s}, {'\0', NULL}
	};
	for (i = 0; my_format_my_stype[i].my_format != '\0'; i++)
		if (my_format[*ind] == my_format_my_stype[i].my_format)
			return (my_format_my_stype[i].fn
					(list, my_buff, flags, breadth, my_pre, size));

	if (my_format_my_stype[i].my_format == '\0')
	{
		if (my_format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (my_format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (breadth)
		{
			--(*ind);
			while (my_format[*ind] != ' ' && my_format[*ind] != '%')
				--(*ind);
			if (my_format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &my_format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
