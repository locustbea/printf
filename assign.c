#include "main.h"

/**
 * _assign - assigned and count functions
 * @buff: str var
 * @count: index counters
 * @value: value in the index and sub 
 * Return: int
 */

int _assign(char *buff, int count, char *value)
{
	int e = 0;

	while (value[e])
	{
		buff[e] = value[e];
		count++;
	}
	return (count);

}

/**
 * _rev_assign - reversed assigning function  and return count
 * @buff: str var
 * @count: index counter
 * @value: value in the index
 * return: int
 */

int _rev_assign(char *buff, int count, char *value)
{
	int len = _strlen(valu);
	int e;

	for (e = 0; e <= len; e++)
	{
		buff[e] = value[len - e];
		count++;
	}
	return (count);
}
