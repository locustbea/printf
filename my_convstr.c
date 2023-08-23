#include "main.h"

/**
 * my_conv - this func converts bases and numbers to str
 * @n: input number
 * @b: the input base
 * @lcase: this is needed if hexadecimal value need to be lowercase
 * Return: output string
 */

char *my_conv(unsigned long int n, int b, int lcase)
{
	static char buffer[50];
	char *ptr;
	static char *r;

	r = (lcase)
	? "0123456789abcdef"
	: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
	*--ptr = r[n % b];
	n /= b;
	} while
		(n != 0);
	return (ptr);
}
