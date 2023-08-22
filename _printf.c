#include "main.h"

void print_buffer(char buffer[], int *buff_indoz);
/**
 * _printf - a printf similar func
 * @format: for format
 * Return: the printed chars
 */
int _printf(const char *format, ...)
{
	int i, printedx = 0, printed_xchars = 0;
	int width, flags, precision, size, buff_indoz = 0;
	va_list all_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(all_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_indoz++] = format[i];
			if (buff_indoz == BUFF_SIZE)
				print_buffer(buffer, &buff_indoz);

			printed_xchars++;
		}
		else
		{
			print_buffer(buffer, &buff_indoz);
			flags = get_flags(format, &i);
			width = get_width(format, &i, all_list);
			precision = get_precision(format, &i, all_list);
			size = get_size(format, &i);
			++i;
			printedx = hdl_print(format, &i, all_list, buffer,
				flags, width, precision, size);
			if (printedx == -1)
				return (-1);
			printed_xchars += printedx;
		}
	}

	print_buffer(buffer, &buff_indoz);

	va_end(all_list);

	return (printed_xchars);
}
/**
 * print_buffer - print the buffer content if exists
 * @buffer: char array
 * @buff_indoz: next char len
 */
void print_buffer(char buffer[], int *buff_indoz)
{
	if (*buff_indoz > 0)
		write(1, &buffer[0], *buff_indoz);

	*buff_indoz = 0;
}
