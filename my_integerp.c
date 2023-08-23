#include "main.h"

/**
* my_numbp - This func loops through an integer and prints the digits
* @n: input number
*/

void my_numbp(int n)
{
	unsigned int num1;

	if (n < 0)
	{
	_putchar('-');
	num1 = -n;
	}
	else
	num1 = n;
	if (num1 / 10)
	my_numbp(num1 / 10);
	 _putchar((num1 % 10) + '0');
}

/**
* my_digitcounter - This function prints the number of digits in an int
* @n: number to check
* Return: number of digits
*/

int my_digitcounter(int n)
{
	unsigned int a = 0;
	unsigned int a1;

	if (n < 0)
	a1 = n  * -1;
	else
	a1 = n;
	while (a1 != 0)
	{
	a1 /= 10;
	a++;
	}
	return (a);
}

/**
* integer1_p - this func prints an int
* @l: va_list of arguments
* @b: pointer to the struct my_flags
* Return: the character printed
*/

int integer1_p(va_list l, my_flags_t *b)
{
	int n = va_arg(l, int);
	int r = my_digitcounter(n);

	if (b->my_space == 1 && b->my_addsign == 0 && n >= 0)
	r += _putchar(' ');
	if (b->my_addsign == 1 && n >= 0)
	r += _putchar('+');
	if (n < 0)
	my_numbp(n);
	return (r);
}

/**
* unsigned_p - This func prints an unsigned integer
* @l: va_list of arguments
* @b: pointer to the struct my_flags
* Return: the character printed
*/

int unsigned_p(va_list l, my_flags_t *b)
{
	unsigned int a = va_arg(l, unsigned int);
	char *str = my_conv(a, 10, 0);

	(void)b;
	return (_puts(str));
}
