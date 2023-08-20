#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);

/**
 * struct my_flags - This struct contains my defined flags
 * @my_addsign: the '+' character
 * @my_space: the ' ' character
 * @my_hash: the '#' character
 */

typedef struct my_flags
{
	int my_addsign;
	int my_space;
	int my_hash;
} my_flags_t;

int (*my_getp(char s))(va_list, my_flags_t *);
int my_getf(char s, my_flags_t *b);

#endif
