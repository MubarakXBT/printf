#include "main.h"
#include <stdarg.h>
/**
 * _printf - function for format printing
 * @format: list of arguments to printing
 *
 * Return: Number of characters to printing
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	/* Pointer to function "Va_list" */
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;

	/** initialise the pointer to the arguments */
	va_start(ptr, format);
	/* Traversing between element of format */
	for (; format[i] != '\0'; i++)
	{
		/* when element is not '%' */
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			continue;
		}
		/* when element is '%' */
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 1;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 1;
				counter += f(ptr);
				continue;
			}
		}
	}
	va_end(ptr);
	return (counter);
}
