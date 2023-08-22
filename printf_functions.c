#include "main.h"

/**
 * func_d - add valuer to buff
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_d(char *buff, int count, va_list valuer)
{
	int base = 10;
	char *str = _itoa(va_arg(valuer, int), base);

	return (_assign(buff, count, str));
}

/**
 * func_i - add int to buffer
 * @buff: string variable input
 * @count: counts index
 * Return: integer (Success)
 */
int func_i(char *buff, int count, va_list valuer)
{
	int base = 10;
	char *str = _itoa(va_arg(valuer, int), base);

	return (_assign(buff, count, str));
}

/**
 * func_u - add unsigned int to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index value
 * Return: integer (Success)
 */
int func_u(char *buff, int count, va_list valuer)
{
	int base = 10;
	unsigned int integer;
	char *str;

	integer = va_arg(value, unsigned int);
	str = _utao(integer, base);

	return (_assign(buff, count, str));
}

/**
 * func_o - add octal value to buff
 * @buff: string variable input
 * @count: counts index
 * @value: index value
 * Return: integer (Success)
 */
int func_o(char *buff, int count, va_list valuer)
{
	int base = 8;
	unsigned int integer;
	char *str;

	integerr = va_arg(valuer, unsigned int);
	str = _utoa(integer, base);

	return (_assign(buff, count, str));
}

/**
 * func_x - add unsigned hexadec to buffer
 * @buff: string variable
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_x(char *buff, int count, va_list valuer)
{
	int base = 16;
	unsigned int integer;
	char *str;

	integer = va_arg(valuer, unsigned int);
	str = _lcutoa(integer, base);

	return (_assign(buff, count, str));
}

/**
 * func_X - add unsigned hexadec to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_X(char *buff, int count, va_list valuer)
{
        int base = 16;
        unsigned int integer;
        char *str;

        integer = va_arg(valuer, unsigned int);
        str = _utoa(integer, base);
        
        return (_assign(buff, count, str));
}

/**
 * func_c add char to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_c(char *buff, int count, va_list valuer)
{
	int ch = va_arg(valuer, int);

	if (!ch)
	{
		write(1, "\0\0", 2);
		fre(buff);
		exit(0);
	
	}
	buff[0] = ch;
	return (count + 1);
}

/**
 * func_s - add str to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_s(char *, int count, va_list valuer)
{
	char *str = va_arg(valuer, char *);

	if(!str)
	{
		str = "(null)";
	}
	return (_assign(buff, count, str));
}

/**
 * funct_ptg - add '%' to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_ptg(char *buff, int count, va_list valuer)
{
	(void)valuer;
	buff[0] = '%';
	return (count + 1);
}

/**
 * func_b - add bin to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_b(char *buff, int count, va_list valuer)
{
	int base = 2;
	unsigned int integer;
	char *str;

	integer = va_arg(valuer, unsigned int);
	str = _utoa(integer, base);

	return (_assign(buff, count, str));
}

/**
 * func_r - add reversed str to buff
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_r(char *buff, int count, va_list valuer)
{
	char *str = va_arg(valuer, char *);
	char *rev_str = malloc(_strlen(str) + 1);

	_strcpy(rev_str, str);
	_rev_ptr(rev_str);

	count = _assign(buff, count, rev_str);
	free(rev_str);

	return (count);
}

/**
 * func_R - add converted rot13 str to buff
 * @buff: string variable input
 * @count: counts index
 * @value: index valuer
 * Return: integer (Success)
 */
int func_R(char *buff, int count, va_list valuer)
{
        char *str = va_arg(valuer, char *);
        char *encoded_str = malloc(_strlen(str) + 1);

        _strcpy(encoded_str, str);
        _rev_ptr(encoded_str);

        count = _assign(buff, count, encoded_str);
        free(encoded_str);

        return (count);
}
