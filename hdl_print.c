#include "main.h"

/**
 * hdl_print - a function that prints an argument according to its type
 * @frmt: formatted string to print the arguments
 * @list: a list of arguments to be printed
 * @i: ind
 * @buffer: buffer array to handle print
 * @flags: to calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */
int hdl_print(const char *frmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int j, len = 0, chaa = -1;
	frmt_t frmt_types[] = {
		{'c', prnt_char}, {'s', prnt_string}, {'%', prnt_percent},
		{'i', prnt_int}, {'d', prnt_int}, {'b', prnt_binary},
		{'u', prnt_unsigned}, {'o', prnt_octa}, {'x', prnt_hexadec},
		{'X', prnt_hexaup}, {'p', prnt_ptr}, {'S', prnt_non_prntable},
		{'r', prnt_rev}, {'R', prnt_rot13str}, {'\0', NULL}
	};
	for (j = 0; frmt_types[j].frmt != '\0'; j++)
		if (frmt[*i] == frmt_types[j].frmt)
			return (frmt_types[j].fun(list, buffer, flags, width, precision, size));

	if (frmt_types[j].frmt == '\0')
	{
		if (frmt[*i] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (frmt[*i - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (frmt[*i] != ' ' && frmt[*i] != '%')
				--(*i);
			if (frmt[*i] == ' ')
				--(*i);
			return (1);
		}
		len += write(1, &frmt[*i], 1);
		return (len);
	}
	return (chaa);
}
