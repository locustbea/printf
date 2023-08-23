#include "main.h"

/**
 * my_getp - this func checks the conversion specifier passed to
 * _printf and selects the appropriate printing function
 * @s: this character stores the conversion specifier
 *
 * Return: a pointer to the right printing func
 */

int (*my_getp(char s))(va_list, my_flags_t *)
{
	my_ph func_arr[] = {
	{'%', percent_p},
	{'b', binary_p},
	{'c', character_p},
	{'d', integer_p},
	{'i', integer1_p},
	{'o', octal_p},
	{'p', address_p},
	{'r', reverse_p},
	{'R', rot13_p},
	{'s', string_p},
	{'S', stringbig_p},
	{'u', unsigned_p},
	{'x', hexa_p},
	{'X', hexabig_p},
	};

	int my_flags = 14;

	register int i;

	for (i = 0; i < my_flags; i++)
	if (func_arr[i].c == s)
	return (func_arr[i].b);
	return (NULL);
}
