#include "main.h"

/**
 * my_getp - Calculates the my_pre for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: my_pre.
 */
int my_getp(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int my_pre = -1;

	if (format[curr_i] != '.')
		return (my_pre);

	my_pre = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (my_digit(format[curr_i]))
		{
			my_pre *= 10;
			my_pre += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			my_pre = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (my_pre);
}
