#include "main.h"
/*For the Unsigned number*/
/**
 * prnt_unsigned - Prints an unsigned number
 * @types: list of arg
 * @buffer: array buffer for int
 * @flags: calc flags
 * @width: width
 * @precision: prec
 * @size: for size
 * Return: the number of chars that has been printed
 */
int prnt_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wt_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*Print unsgned in Octal*/
/**
 * prnt_octa - print num in octal
 * @types: list argu
 * @buffer: array buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: char printed
 */
int prnt_octa(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int initx_num = num;

	UNUSED(width);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && initx_num != 0)
		buffer[i--] = '0';

	i++;

	return (wt_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*HexaDecimal unsigned print*/
/**
 * prnt_hexadec - Prints an unsigned number in hexadecimal notation
 * @types: list
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: prec.
 * @size: size
 * Return: char to be printed
 */
int prnt_hexadec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prnt_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/*Capital HexaDecimal print*/
/**
 * prnt_hexaup - Prints an unsigned number in upper hexadecimal notation
 * @types: list
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: char to be printed
 */
int prnt_hexaup(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prnt_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/*Capital or small in HexaDecimal*/
/**
 * prnt_hexa - print hexadecimal number in small or capital
 * @types: lists
 * @mp_to: array to map
 * @buffer: buffer array
 * @flags: flags
 * @flag_ch: flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier.
 * @size: Size specifications.
 * Return: Number of chars printed
 */
int prnt_hexa(va_list types, char mp_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int numx = va_arg(types, unsigned long int);
	unsigned long int initx_num = numx;
	int i = BUFF_SIZE - 2;

	UNUSED(width);

	numx = conv_size_unsgnd(numx, size);

	if (numx == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numx > 0)
	{
		buffer[i--] = mp_to[numx % 16];
		numx /= 16;
	}

	if (flags & F_HASH && initx_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (wt_unsgnd(0, i, buffer, flags, width, precision, size));
}
