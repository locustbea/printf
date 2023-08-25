#include "main.h"

/**
 * my_getf - this func activates the flags when needed by _printf
 * @s: this char holds the flag specifier
 * @b: this is a pointer to the struct my_flags.
 *
 * Return: if the flag is activated 1, else, return 0
 */

int my_getf(char s, my_flags_t *b)
{
	int c = 0;

	switch (s)
	{
	case ' ':
	b->my_space = 1;
	c = 1;
	break;
	
	case '#':
	b->my_hash = 1;
	c = 1;
	break;

	case '+':
	b->my_addsign = 1;
	c = 1;
	break;
	}
	return (c);
}
