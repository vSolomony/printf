#include "main.h"
/*Func. to print pointer*/
/**
 * prnt_ptr - Prints the value of a pointer variable
 * @types: lists
 * @buffer: buffer array
 * @flags: flags
 * @width: get width
 * @precision: Precision
 * @size: Size
 * Return: char to be printed.
 */
int prnt_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_cs = 0, paddin = ' ';
	int indxx = BUFF_SIZE - 2, len = 2, paddin_start = 1;
	unsigned long num_addres;
	char mp_to[] = "0123456789abcdef";
	void *addrss = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrss == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addres = (unsigned long)addrss;

	while (num_addres > 0)
	{
		buffer[indxx--] = mp_to[num_addres % 16];
		num_addres /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddin = '0';
	if (flags & F_PLUS)
		extra_cs = '+', len++;
	else if (flags & F_SPACE)
		extra_cs = ' ', len++;

	indxx++;

	return (wt_ptr(buffer, indxx, len,
		width, flags, paddin, extra_cs, paddin_start));
}

/*ALL NON PRINTABLE*/
/**
 * prnt_non_prntable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prnt_non_prntable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offxset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_prntable(str[i]))
			buffer[i + offxset] = str[i];
		else
			offxset += app_hexa_code(str[i], buffer, i + offxset);

		i++;
	}

	buffer[i + offxset] = '\0';

	return (write(1, buffer, i + offxset));
}
/*Priting Reverse*/
/**
 * prnt_rev - Prints reverse string.
 * @types: lists
 * @buffer: array buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars the has been printed
 */
int prnt_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, coo_n = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		coo_n++;
	}
	return (coo_n);
}
/*Printing Strings in rot 13*/
/**
 * prnt_rot13str - rot13 printing
 * @types: lists
 * @buffer: array buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: char that has been printed
 */
int prnt_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x_y;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x_y = out[j];
				write(1, &x_y, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x_y = str[i];
			write(1, &x_y, 1);
			count++;
		}
	}
	return (count);
}
