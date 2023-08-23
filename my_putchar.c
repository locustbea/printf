#include <unistd.h> 
#include "main.h"

/** 
 * _putchar - writes the character c to stdout 
 * @c: The character to print 
 *
 * Return: On success 1. 
 * On error, -1 is returned, and errno is set appropriately. 
 */

int _putchar(char c) 
{ 
	return (write(1, &c, 1)); 
} 

/**
 * _puts - this func prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int a;

	for (a = 0; str[a] != '\0'; a++)
	putchar(str[a]);
	return (a);
}
