#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define my_longs 2
#define my_shorts 1

#define my_subsign 1
#define my_addsign 2
#define my_null 4
#define my_hash 8
#define my_space 16

/**
 * struct my_format - Struct op
 *
 * @my_format: this is the format.
 * @fn: The function associated.
 */
struct my_format
{
	char my_format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct my_format my_format_t - Struct op
 *
 * @my_format: The format.
 * @fm_t: The function associated.
 */

typedef struct my_format my_format_t;

int _printf(const char *format, ...);
int my_ph(const char *my_format, int *i,
		va_list list, char my_buff[], int flags, int breadth, int my_pre, int size);


/* chars and strings functions */
int my_characterp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_stringp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_percentp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

/* integer functions */
int my_intp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_binaryp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_unsignedp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_octalp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_hexaD(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_hexabig(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

int my_hexap(va_list my_stype, char map_to[],
		char my_buff[], int flags, char flag_ch, int breadth, int my_pre, int size);

/* Non printable characters function */
int my_nonprintablep(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

/* Memory address functions*/
int my_pointerp(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

/* Specifier functions */
int my_getf(const char *format, int *i);
int my_getw(const char *format, int *i, va_list list);
int my_getp(const char *format, int *i, va_list list);
int my_gets(const char *format, int *i);

/* Reverse functions*/
int my_reversep(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

/* Rot13 function*/
int my_rot13s(va_list my_stype, char my_buff[],
			int flags, int breadth, int my_pre, int size);

/* breadth handler */
int my_charwrite(char c, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_nwrite(int is_positive, int ind, char my_buff[],
			int flags, int breadth, int my_pre, int size);
int my_nmwrite(int ind, char bfer[], int flags, int breadth, int my_pre,
			int length, char padd, char extra_c);
int my_pwrite(char my_buff[], int ind, int length,
			int breadth, int flags, char padd, char extra_c, int my_startpadding);

int my_uwrite(int is_negative, int ind,
		char my_buff[],
			int flags, int breadth, int my_pre, int size);


int my_printables(char);
int my_hexcodeapp(char, char[], int);
int my_digit(char);

long int my_convlong(long int num, int size);
long int my_convunsigned(unsigned long int num, int size);

#endif
