/* Required Headers */
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *_printf - Prototype for Printf function
 *@fmt: The argument to be printed
 *Description: This program Will provide a minimal function of printf
 *
 * Return: The program should return The numbers of characters printed
 */
int _printf(const char *format, ...)
{
	/* Declaration of variables*/
	int dval, ival;
	int count = 0;
	char *cval, *sval;
	const char *init;
	double fval;

	/* Declare pointer for argument list */
	va_list ptr;

	/* Initiaise argument to the list pointer*/
	va_start(ptr, format);

	/* Traversing along the arguments*/
	for(init = format; *init != '\0'; init++)
	{
		count += 1;
		if (*init  != '%')
		{
			putchar(*init);
			continue;
		}
		init++;
		switch(*init)
		{
			case 'i':
				ival = va_arg(ptr, int);
				printf("%i", ival);
				break;
			case 'd':
				dval = va_arg(ptr, int);
				printf("%d", dval);
				break;
			case 'f':
				fval = va_arg(ptr, double);
				printf("%f", fval);
				break;
			case 'c':
				cval = va_arg(ptr, char*);
				printf("%s", cval);
			case 's':
				sval = va_arg(ptr, char*);
				printf("%s", sval);
				break;
			default:
				putchar(*init);
				break;
		}
	}
	va_end(ptr);
	return (count);
}
