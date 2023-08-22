#ifndef MAIN_H
#define MAIN_H
<<<<<<< HEAD
#include <stdio.h>

/* PROTOTYPES */
int_printf(const char *format, ...);

#endif /* end of MAIN_H */
=======

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
int my_getf(char a, my_flags_t *b);
char *my_conv(unsigned long int n, int b, int lcase);

#endif
>>>>>>> ea793ce43cf626b68897a48ac9d1d5098d47c413
