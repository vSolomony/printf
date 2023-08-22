#include "main.h"

/**
 * get_precision -  a function that calculates the precision for printing
 * @format: Formatted string to print the arguments
 * @i: a list of arguments
 * @list: a list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int k = *i + 1;
	int precision = -1;

	if (format[k] != '.')
		return (precision);

	precision = 0;

	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digt(format[k]))
		{
			precision *= 10;
			precision += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (precision);
}
