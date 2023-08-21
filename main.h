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
char *my_conv(unsigned long int n, int b, int lcase);

typedef struct my_ph
{
	char c;
	int (*b)(va_list ap, my_flags_t *b);
} my_ph;

/* Elements of arrayf[] */
int percent_p(va_list l, my_flags_t *b);
int binary_p(va_list l, my_flags_t *b);
int character_p(va_list l, my_flags_t *b);
int integer_p(va_list l, my_flags_t *b);
int integer1_p(va_list l, my_flags_t *b);
int octal_p(va_list l, my_flags_t *b);
int address_p(va_list l, my_flags_t *b);
int reverse_p(va_list l, my_flags_t *b);
int rot13_p(va_list l, my_flags_t *b);
int string_p(va_list l, my_flags_t *b);
int stringbig_p(va_list l, my_flags_t *b);
int unsigned_p(va_list l, my_flags_t *b);
int hexa_p(va_list l, my_flags_t *b);
int hexabig_p(va_list l, my_flags_t *b);

#endif
