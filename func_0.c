#include "main.h"

/** a function to print a char **/

/**
 * prnt_char - a function that prints a character
 * @types: this is a list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specify the size 
 * Return: printed chars
 */

int prnt_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (int handle_wt_char(c, buffer, flags, width, precision, size));
}

/** a function to print a string **/
/**
 * print_string - a function to print a string
 * @types: this is a list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specify the size
 * Return: printed chars
 */

int prnt_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/** a function to print a percent sign **/
/**
 * 
 * print_percent - a function to print a percent sign
 * @types: this is a list of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specify the size
 * Return: printed chars
 */
int prnt_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** a function to print an int **/
/**
 * print_int - a function to print an int
 * @types: this is a list of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specify the size
 * Return: printed chars
 */
int prnt_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negt = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = conv_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negt = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wt_number(is_negt, i, buffer, flags, width, precision, size));
}

/** a function to print a binary **/
/**
 * print_binary - a function to print a binary
 * @types: this is a list of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: specify the size
 * Return: printed chars
 */
int prnt_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

