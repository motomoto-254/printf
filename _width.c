#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curry_i;
	int width = 0;

	for (curry_i = *i + 1; format[curry_i] != '\0'; curry_i++)
	{
		if (is_digit(format[curry_i]))
		{
			width *= 10;
			width += format[curry_i] - '0';
		}
		else if (format[curry_i] == '*')
		{
			curry_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curry_i - 1;

	return (width);
}
