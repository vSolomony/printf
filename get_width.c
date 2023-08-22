#include "main.h"

/**
 * get_width - a function that calculates the width for printing
 * @format: formatted string to print the arguments
 * @i: a list of arguments to be printed
 * @list: a list of arguments
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int k;
	int width = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (is_digt(format[k]))
		{
			width *= 10;
			width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (width);
}

