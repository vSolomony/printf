#include "main.h"
/*Handling Write*/
/**
 * handle_wt_char - Prints a string
 * @c: a char
 * @buffer: array buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: Size
 * Return: char that has been printed
 */
int handle_wt_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char paddin = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		paddin = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = paddin;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/*Number using write func*/
/**
 * wt_number - Prints a string
 * @is_post: Lists
 * @ind: char types of all.
 * @buffer: array buffer
 * @flags: flags
 * @width: width.
 * @precision: precision
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int wt_number(int is_post, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char paddin = ' ', extr_xch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddin = '0';
	if (is_post)
		extr_xch = '-';
	else if (flags & F_PLUS)
		extr_xch = '+';
	else if (flags & F_SPACE)
		extr_xch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, paddin, extr_xch));
}
/**
 * wt_num - number using a buffer using write
 * @ind: first index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision
 * @length: length
 * @padd: Pading
 * @extra_c: Extra char
 * Return: no of printed chars
 */
int wt_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - insigned write
 * @is_negt: if negative
 * @ind: Index
 * @buffer: char array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: no. of printed chars
 */
int wt_unsgnd(int is_negt, int ind,
	char buffer[], int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char paddin = ' ';

	UNUSED(is_negt);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		paddin = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddin = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = paddin;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}
/**
 * wt_ptr - for memory
 * @buffer: char array
 * @ind: Index
 * @length: Length
 * @width: Wwidth
 * @flags: Flags
 * @padd: Char padd
 * @extra_c: Char extra
 * @padd_start: Index of padd
 * Return: no. of printed chars.
 */
int wt_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
