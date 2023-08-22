#include "main.h"
/**
 * get_flags - a function that calculates active flags
 * @format: formatted string to print the arguments
 * @i: takes a parameter.
 * Return: printed flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int h, k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (h = 0; FLAGS_CH[h] != '\0'; h++)
			if (format[k] == FLAGS_CH[h])
			{
				flags |= FLAGS_ARR[h];
				break;
			}

		if (FLAGS_CH[h] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}
