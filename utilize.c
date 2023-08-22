#include "main.h"
/**
 * is_prntable - a function that evaluates if a char is printable
 * @c: char to be evaluated.
 * Return: 1 if c is printable, if else returns 0
 */
int is_prntable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * app_hexa_code - append ascci in hexadecimal code in order to buffer
 * @buffer: an array of chars
 * @i: an index to start appending
 * @ascii_code: ASSCI code
 * Return: always 3
 */
int app_hexa_code(char ascii_code, char buffer[], int i)
{
	char mp_to[] = "0123456789ABCDEF";

	/* hexa format code is 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = mp_to[ascii_code / 16];
	buffer[i] = mp_to[ascii_code % 16];

	return (3);
}
/**
 * is_digt - a function that verifies if a char is a digit
 * @c: a character to be evaluated
 * Return: 1 if c is a digit, if else return 0
 */
int is_digt(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * conv_size_number - a function that casts a number to a specific size
 * @n: a number to be casted.
 * @size: number indicating the type to be casted.
 * Return: casted value of n
 */
long int conv_size_number(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);

	return ((int)n);
}
/**
 * conv_size_unsgnd - a function that casts a number to a specific size
 * @n: a number to be casted
 * @size: Number indicating the type to be casted
 * Return: casted value of n
 */
long int conv_size_unsgnd(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
