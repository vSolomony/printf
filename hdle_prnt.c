#include "main.h"
/**
 * hdle_prnt - a function that prints an argument according to its type
 * @frmt: formatted string to print the arguments
 * @list: a list of arguments to be printed
 * @ind: ind
 * @buffer: buffer array to handle print
 * @flags: to calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */
int hdle_prnt(const char *frmt, int *ind,
va_list list, int precision, int flags, int size, char buffer[], int width)
{
	int i, length = 0, chars = -1;
	frmt_t frmt_types[] = {
		{'c', prnt_char}, {'s', prnt_string}, {'%', prnt_percent},
		{'i', prnt_int}, {'d', prnt_int}, {'b', prnt_binary},
		{'u', prnt_unsigned}, {'o', prnt_octa}, {'x', prnt_hexadec},
		{'X', prnt_hexaup}, {'p', prnt_ptr}, {'S', prnt_non_prntable},
		{'r', prnt_rev}, {'R', prnt_rot13str}, {'\0', NULL}
	};
	for (i = 0; frmt_types[i].frmt != '\0'; i++)
		if (frmt[*ind] == frmt_types[i].frmt)
			return (frmt_types[i].fun(list, buffer, flags, width, precision, size));

	if (frmt_types[i].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		length += write(1, &frmt[*ind], 1);
		return (length);
	}
	return (chars);
}
