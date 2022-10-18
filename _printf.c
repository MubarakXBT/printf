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
	int dval;
	unsigned int ival;
	int count = 0;
	char cval, *sval;
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
				cval = (char)va_arg(ptr, int);
				printf("%c", cval);
				break;
			case 's':
				sval = va_arg(ptr,char *);
				puts(sval);
				break;
			case 'o':
				ival = va_arg(ptr, unsigned int);
				printf("%o", ival);
				break;
			case'u':
				ival = va_arg(ptr, unsigned int);
				printf("%u", ival);
				break;
			case'x':
				ival = va_arg(ptr, unsigned int);
				printf("%x", ival);
				break;
			case'X':
				ival = va_arg(ptr, unsigned int);
				printf("%X", ival);
				break;
			default:
				putchar(*init);
				break;
		}
	}
	va_end(ptr);
	return (count);
}
